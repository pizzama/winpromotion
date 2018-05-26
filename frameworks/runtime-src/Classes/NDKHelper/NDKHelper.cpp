//
//  NDKHelper.cpp
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#include "NDKHelper.h"

#define __CALLED_METHOD__           "calling_method_name"
#define __CALLED_METHOD_PARAMS__    "calling_method_params"

#define KGlobleNativeMessage        "k_globle_message"
#define KLocalNativeMessage         "k_local_message"

#define USE_LUA
#ifdef USE_LUA
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#endif

vector<NDKCallbackNode> NDKHelper::selectorList;

void NDKHelper::AddSelector(const char *groupName, const char *name, SEL_CallFuncND selector, Node* target)
{
    NDKHelper::selectorList.push_back(NDKCallbackNode(groupName, name, selector, target));
}

void NDKHelper::RemoveAtIndex(int index)
{
    NDKHelper::selectorList[index] = NDKHelper::selectorList.back();
    NDKHelper::selectorList.pop_back();
}

void NDKHelper::RemoveSelectorsInGroup(const char *groupName)
{
    std::vector<int> markedIndices;
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i)
    {
        if (NDKHelper::selectorList[i].getGroup().compare(groupName) == 0)
        {
            markedIndices.push_back(i);
        }
    }
    
    for (unsigned int i = 0; i < markedIndices.size(); ++i)
    {
        NDKHelper::RemoveAtIndex(markedIndices[i]);
    }
}

void NDKHelper::PrintSelectorList()
{
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i)
    {
        string s = NDKHelper::selectorList[i].getGroup();
        s.append(NDKHelper::selectorList[i].getName());
        CCLog("selector is %s", s.c_str());
    }
}


void NDKHelper::HandleMessage(const string &methodName, const char* methodParams)
{
    CCLOG("test");
    if (methodName.length() == 0)
        return;
    
    for (unsigned int i = 0; i < NDKHelper::selectorList.size(); ++i)
    {
        if (NDKHelper::selectorList[i].getName().compare(methodName) == 0)
        {
            
            if (NDKHelper::selectorList[i].getTarget() != NULL) {
                SEL_CallFuncND sel = NDKHelper::selectorList[i].getSelector();
                Node *target = NDKHelper::selectorList[i].getTarget();
                if (sel) {
                    (target->*sel)(target, (void *)methodParams);
                }
            } else
            {
#ifdef USE_LUA
                int handler = NDKHelper::selectorList[i].getLuaHandler();
                if (handler > 0) {
                    LuaEngine* pEngine = (LuaEngine*)LuaEngine::getInstance();
                    LuaStack* pStack = pEngine->getLuaStack();
                    if (methodParams == NULL) {
                        pStack->pushString("{}");
                    } else
                    {
                        pStack->pushString(methodParams);
                    }
                    pStack->executeFunctionByHandler(handler, 1);
                    pStack->clean();
                }
#endif
            }
            
            if (NDKHelper::selectorList[i].getGroup().compare(KLocalNativeMessage) == 0) {
                NDKHelper::selectorList[i].unRegisterScriptHandler();
                NDKHelper::RemoveAtIndex(i);
            }
            break;
        }
    }
}

//below for lua call
void NDKHelper::sendMessageToNative(const char *methodName, const char* params, int handler)
{
    if (handler > 0 ) {
        int size = NDKHelper::selectorList.size();
        int index = -1;
        for (unsigned int i = 0; i < size; ++i)
        {
            if (NDKHelper::selectorList[i].getName().compare(methodName) == 0)
            {
                //如果存在,替换之前的handler
                index = i;
                NDKHelper::selectorList[i].registerScriptHandler(handler);
                break;
            }
        }
        
        //如果不存在,添加到监听队列中
        if (index < 0) {
            
            NDKHelper::selectorList.push_back(NDKCallbackNode(KLocalNativeMessage, methodName, handler));
        }
    }
    
    SendMessageWithParams(methodName, params);
}

void NDKHelper::listenNativeMessage(const char *messageName, int handler)
{
    if (messageName == NULL || handler <= 0) {
        return;
    }
    
    int size = NDKHelper::selectorList.size();
    int index = -1;
    for (unsigned int i = 0; i < size; ++i)
    {
        if (NDKHelper::selectorList[i].getName().compare(messageName) == 0)
        {
            //如果存在,替换之前的handler
            index = i;
            NDKHelper::selectorList[i].registerScriptHandler(handler);
            break;
        }
    }
    
    //如果不存在,添加到监听队列中
    if (index < 0) {
        
        NDKHelper::selectorList.push_back(NDKCallbackNode(KGlobleNativeMessage, messageName, handler));
    }
}

//lua reload的时候需要调用此函数
void NDKHelper::reset()
{
    int size = NDKHelper::selectorList.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        NDKHelper::selectorList[i].unRegisterScriptHandler();
    }
    NDKHelper::selectorList.clear();
}



#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "../../cocos/platform/android/jni/JniHelper.h"
    #include <android/log.h>
    #include <jni.h>
    #define  LOG_TAG    "EasyNDK-for-cocos2dx"

//    #define CLASS_NAME "com/easyndk/classes/AndroidNDKHelper"

    #define CLASS_NAME "org/cocos2dx/easyndk/AndroidNDKHelper"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #import "IOSNDKHelper-C-Interface.h"
#endif

extern "C"
{
    //jstring to char*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
   	char* jstringTostring(JNIEnv* env, jstring jstr)
   	{
        char* rtn = NULL;
        jclass clsstring = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("utf-8");
        jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
        jsize alen = env->GetArrayLength(barr);
        jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
        if (alen > 0)
        {
            rtn = (char*)malloc(alen + 1);
            memcpy(rtn, ba, alen);
            rtn[alen] = 0;
        }
        env->ReleaseByteArrayElements(barr, ba, 0);
        return rtn;
   	}
#endif
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // Method for recieving NDK messages from Java, Android
    void Java_org_cocos2dx_easyndk_AndroidNDKHelper_CPPNativeCallHandler(JNIEnv* env, jobject thiz, jstring method, jstring params)
    {
        // Just to see on the log screen if messages are propogating properly
        char *temp1 = jstringTostring(env, method);
        char *temp2 = jstringTostring(env, params);
        std::string str = temp1;
        NDKHelper::HandleMessage(str, temp2);
        
        //内存释放
        free(temp1);
        free(temp2);
    }
    #endif
    
    // Method for sending message from CPP to the targetted platform
    void SendMessageWithParams(const string& methodName, const char* methodParams)
    {
        if (methodName.length() == 0)
            return;
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t,
                                           CLASS_NAME,
                                           "RecieveCppMessage",
                                           "(Ljava/lang/String;Ljava/lang/String;)V"))
		{
            
            jstring stringArg1 = t.env->NewStringUTF(methodName.c_str());
            if (methodParams != NULL) {
                
                jstring stringArg2 = t.env->NewStringUTF(methodParams);
                t.env->CallStaticVoidMethod(t.classID, t.methodID, stringArg1, stringArg2);
                t.env->DeleteLocalRef(stringArg2);
                
            } else
            {
                jstring stringArg2 = t.env->NewStringUTF("{}");
                t.env->CallStaticVoidMethod(t.classID, t.methodID, stringArg1, stringArg2);
                t.env->DeleteLocalRef(stringArg2);
            }
            t.env->DeleteLocalRef(stringArg1);
			t.env->DeleteLocalRef(t.classID);
		}
        #endif
        
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

        IOSNDKHelperImpl::RecieveCPPMessage(methodName, methodParams);

        #endif
    }

}
