//
//  NDKHelper.h
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#ifndef __EasyNDK_for_cocos2dx__NDKHelper__
#define __EasyNDK_for_cocos2dx__NDKHelper__

#include <iostream>
#include "cocos2d.h"
#include <string>
#include <vector>
#include "NDKCallbackNode.h"
USING_NS_CC;
using namespace std;

class NDKHelper
{
    private :
        static vector<NDKCallbackNode> selectorList;
        static void RemoveAtIndex(int index);

    public :
        //below for cpp call
        static void AddSelector(const char *groupName, const char *name, SEL_CallFuncND selector, Node* target);
        static void RemoveSelectorsInGroup(const char *groupName);
        static void PrintSelectorList();
        static void HandleMessage(const string &methodName, const char* methodParams);
        ////////////////////////////////////////////////////////////////////////////////////
    
        //below for lua call
        //发送消息到本地
        static void sendMessageToNative(const char *methodName, const char* params, int handler);
        //监听本地的广播
        static void listenNativeMessage(const char *messageName, int handler);
        //lua reload的时候需要调用此函数
        static void reset();
};

extern "C"
{
    void SendMessageWithParams(const string& methodName, const char* methodParams);
}

#endif /* defined(__EasyNDK_for_cocos2dx__NDKHelper__) */
