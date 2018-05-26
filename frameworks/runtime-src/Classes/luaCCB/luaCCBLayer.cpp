//
//  luaCCBLayer.cpp
//  testLuaCCB_2.0.4
//
//  Created by yock on 13-1-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "luaCCBLayer.h"

#include "GUI/CCControlExtension/CCInvocation.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#include "scripting/lua-bindings/manual/CCLuaEngine.h"


#define KNoneScriptHandle   0

/* Forward declaration. */
//class CCBReader;
using namespace std;

luaCCBNode::luaCCBNode()
{
    m_rViewDiction = NULL;
    m_hAnimationManager = NULL;
    m_nAnimHandle = 0;
}
luaCCBNode::~luaCCBNode()
{
//    CCLOG("--------luaCCBNode will be delete that with %s",m_sCCBName.c_str());
    if(m_rViewDiction)
        m_rViewDiction->release();
    std::map<std::string, int>::iterator it;
    for(it = m_rMethodArray.begin() ; it!=m_rMethodArray.end() ; ++it)
    {
        ScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(it->second);
    }
    m_rMethodArray.clear();
    unregisterAnimFunc();
}
//the method is not used with us
luaCCBNode* luaCCBNode::create()
{
    luaCCBNode* node = new luaCCBNode();
    if(node->init())
    {
        node->autorelease();
        return node;
    }
    delete node;
    return NULL;
}

void luaCCBNode::addPublicResource(const char* plist)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
    Dictionary *dict = Dictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
    if(dict == NULL)
        return;
    Dictionary *dframe = (Dictionary*)dict->objectForKey("frames");
    DictElement* pElement = NULL;
    CCDICT_FOREACH(dframe, pElement)
    {
        std::string spriteFrameName = pElement->getStrKey();
        SpriteFrame* spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName.c_str());
        if(spriteFrame)
            spriteFrame->retain();
    }
    dict->release();
}

bool luaCCBNode::init()
{
    m_rMethodArray.clear();
    m_rViewDiction = CCDictionary::create();
    if(m_rViewDiction==NULL) return false;
    m_rViewDiction->retain();
//    Invocation::usedScript(true);
    return true;
}

bool luaCCBNode::openCCBFile(const char* pCCBFileName)
{
//        CCLOG("----------luaCCBNode open %s file",pCCBFileName);
        cocosbuilder::NodeLoaderLibrary *ccNodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
        
        ccNodeLoaderLibrary->registerNodeLoader("luaCCBLayer", luaCCBLoader::loader());
        
        cocosbuilder::CCBReader *ccbReader = new cocosbuilder::CCBReader(ccNodeLoaderLibrary);
        Node *node = ccbReader->readNodeGraphFromFile(pCCBFileName, this);
        m_hAnimationManager = ccbReader->getAnimationManager();
    
        ccbReader->autorelease();
//    CCLayer* layer = (CCLayer*)node;
//    node->getChildren()->count();
//     CCLog("%d", node->getChildren()->count());
        if(node == NULL)
        {
            return false;
        }
        m_hAnimationManager->retain();
//        m_hAnimationManager->setDelegate(this);
        setContentSize(node->getContentSize());
        this->addChild(node);
        m_sCCBName = pCCBFileName;
    
        this->registerAnimFunc(0);
//        CCLOG("----------luaCCBNode open %s file is ok",pCCBFileName);
        return true;
}

Ref* luaCCBNode::objectForName(const char* objName)
{
    return m_rViewDiction->objectForKey(objName);
}

//enforcement changed for type
Node*   luaCCBNode::nodeForName(const char* nodeName)
{
    return(Node*)objectForName(nodeName);
}
Sprite* luaCCBNode::spriteForName(const char* spriteName)
{
    return (Sprite*)objectForName(spriteName);
}
cocos2d::ui::Scale9Sprite* luaCCBNode::scale9SpriteForName(const char* scale9SpriteName)
{
    return (cocos2d::ui::Scale9Sprite*)objectForName(scale9SpriteName);
}
Layer*  luaCCBNode::layerForName(const char* layerName)
{
    return (Layer*)objectForName(layerName);
}
LayerColor*  luaCCBNode::layerColorForName(const char* layerColorName)
{
    return (LayerColor*)objectForName(layerColorName);
}
LayerGradient*   luaCCBNode::layerGradientForName(const char* layerGradientName)
{
    return (LayerGradient*)objectForName(layerGradientName);
}
ScrollView*   luaCCBNode::scrollViewForName(const char* scrollViewName)
{
    return (ScrollView*)objectForName(scrollViewName);
}
Label*    luaCCBNode::labelTTFForName(const char* labelTTFName)
{
    return (Label*)objectForName(labelTTFName);
}
Label* luaCCBNode::labelBMFontForName(const char* labelBMFontName)
{
    return (Label*)objectForName(labelBMFontName);
}
ControlButton* luaCCBNode::controlButtonForName(const char* controlButtonName)
{
    return (ControlButton*)objectForName(controlButtonName);
}
ParticleSystemQuad*  luaCCBNode::particleForName(const char* particleName)
{
    return (ParticleSystemQuad*)objectForName(particleName);
}

//--------------------------------------------------------------------
void luaCCBNode::completedAnimationSequenceNamed(const char *name)
{
    LUA_FUNCTION handler = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)this, ScriptHandlerMgr::HandlerType::CALLFUNC);
    if (0 != handler)
    {
        LuaEngine* m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
        LuaStack* luaStack = m_engine->getLuaStack();
        luaStack->pushString(name);
        luaStack->executeFunctionByHandler(handler, 1);
        luaStack->clean();
    }    
}

void luaCCBNode::runAnimations(const char *pName, float fTweenDuration)
{
    if(m_hAnimationManager)
        m_hAnimationManager->runAnimationsForSequenceNamedTweenDuration(pName, fTweenDuration);
}
void luaCCBNode::runAnimations(const char *pName)
{
    if(m_hAnimationManager)
        m_hAnimationManager->runAnimationsForSequenceNamed(pName);
}
void luaCCBNode::onExit()
{
    Node::onExit();
    if(m_hAnimationManager){
//        m_hAnimationManager->setDelegate(nullptr);
        m_hAnimationManager->release();
        m_hAnimationManager = nullptr;
    }
}
bool luaCCBNode::registerAnimFunc(int handle)
{
    unregisterAnimFunc();
    m_nAnimHandle = handle;
    m_hAnimationManager->setDelegate(this);
    
//    if(m_hAnimationManager)
//        m_hAnimationManager->registerScriptDelegateHandler(handle);
    return true;
}
void luaCCBNode::unregisterAnimFunc()
{
    if(m_nAnimHandle>0)
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nAnimHandle);
        m_nAnimHandle=0;
    }
    
//    if(m_hAnimationManager)
//        m_hAnimationManager->unregisterScriptDelegateHandler();
}

bool      luaCCBNode::registerFunctionWithFuncName(const char* funName,int handle)
{
    std::map<std::string, int>::iterator it;
    it = m_rMethodArray.find(funName);
    if(it!=m_rMethodArray.end())
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(it->second);
        LUALOG("[LUA] add lua function %s handle %d",funName,handle);
    }
    std::string key = funName;
    m_rMethodArray[key] = handle;
    
    return true;
}
void      luaCCBNode::unregisterFunctionWithFuncName(const char* funName)
{
    if(m_rMethodArray.size()<=0) return;
    std::map<std::string, int>::iterator it;
    it = m_rMethodArray.find(funName);
    if(it!=m_rMethodArray.end())
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(it->second);
        m_rMethodArray.erase(it);
    }
}

SEL_MenuHandler luaCCBNode::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName)
{
    /*
     //弃用menu族控件
    if(pTarget != this) return NULL;
    int id;
    std::map<std::string, int>::iterator it;
    it = m_rMethodArray.find(pSelectorName->getCString());
    if(it != m_rMethodArray.end())
    {
        id = it->second;
        return *((SEL_MenuHandler*)(&id));
    }
     */
    return NULL;
}
cocos2d::extension::Control::Handler  luaCCBNode::onResolveCCBCCControlLuaFunc(Ref* pTarget, Node * pNode, const char* pSelectorName)
{
    if(pTarget != this || strlen(pSelectorName)<=0) return NULL;
    int id;
    std::map<std::string, int>::iterator it;
    it = m_rMethodArray.find(pSelectorName);
//    CCLog("get a function with name %s\n",pSelectorName->getCString());
    if(it != m_rMethodArray.end())
    {
        id = it->second;
        CCLOG(" ==== ----========  %d", id);
//        + id
//        return *((cocos2d::extension::Control::Handler*)(&id));
        ControlButton * btn = static_cast<ControlButton*>(pNode);
        if(btn!= NULL)
        {
            ScriptHandlerMgr::getInstance()->addObjectHandler((void*)btn, id, (ScriptHandlerMgr::HandlerType)((int)ScriptHandlerMgr::HandlerType::CONTROL_TOUCH_UP_INSIDE));
        }
    }
    return NULL;
}

bool luaCCBNode::onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode)
{
    if(pTarget != this || strlen(pMemberVariableName)<=0) return false;
//    CCLog("get a Member with name %s\n",pMemberVariableName->getCString());
    std::string key = string(pMemberVariableName);
    m_rViewDiction->setObject(pNode, pMemberVariableName);
    return true;
}
void luaCCBNode::onNodeLoaded(Node * pNode, cocosbuilder::NodeLoader * pNodeLoader)
{
    
}

//control button call back
//void luaCCBNode::onControlButtonClicked(Ref * pSender, cocos2d::ui::CCControlEvent pCCControlEvent)
//{
//    
//}
void luaCCBNode::onMenuItemClicked(Ref * pSender)
{
    
}

