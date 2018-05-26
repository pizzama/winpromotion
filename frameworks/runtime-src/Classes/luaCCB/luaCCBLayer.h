//
//  luaCCBLayer.h
//  testLuaCCB_2.0.4
//
//  Created by yock on 13-1-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#ifndef testLuaCCB_2_0_4_luaCCBLayer_h
#define testLuaCCB_2_0_4_luaCCBLayer_h
#include "cocos2d.h"
//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include <map>

USING_NS_CC;
USING_NS_CC_EXT;

class luaCCBNode :
public cocos2d::Node,
public cocosbuilder::CCBSelectorResolver,
public cocosbuilder::CCBMemberVariableAssigner,
public cocosbuilder::NodeLoaderListener,
public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    luaCCBNode();
    ~luaCCBNode();
public:
    //the method is not used with us
    static luaCCBNode* create();
    //add public resource
    static void addPublicResource(const char* plist);
    
public:
    bool init();
    bool openCCBFile(const char* pCCBFileName);
    Node* getCCBReader(const char* pCCBFileName);
    Ref* objectForName(const char* objName);
    
    
    //enforcement changed for type
    cocos2d::Node*   nodeForName(const char* nodeName);
    cocos2d::Sprite* spriteForName(const char* spriteName);
    cocos2d::ui::Scale9Sprite* scale9SpriteForName(const char* scale9SpriteName);
    cocos2d::Layer*  layerForName(const char* layerName);
    cocos2d::LayerColor*  layerColorForName(const char* layerColorName);
    cocos2d::LayerGradient*   layerGradientForName(const char* layerGradientName);
    ScrollView*   scrollViewForName(const char* scrollViewName);
    Label*    labelTTFForName(const char* labelTTFName);
    Label* labelBMFontForName(const char* labelBMFontName);
    ControlButton* controlButtonForName(const char* controlButtonName);
    cocos2d::ParticleSystemQuad*  particleForName(const char* particleName);
    
    
    //check the animation be end
    virtual void completedAnimationSequenceNamed(const char *name);
    void runAnimations(const char *pName, float fTweenDuration);
    void runAnimations(const char *pName);
    bool registerAnimFunc(int handle);
    void unregisterAnimFunc();
    
    
    
    bool      registerFunctionWithFuncName(const char* funName,int handle);
    void      unregisterFunctionWithFuncName(const char* funName);
public:
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName);
    virtual SEL_CallFuncN onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName) { return NULL; };
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Ref * pTarget, const char* pSelectorName){ return NULL;};
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlLuaFunc(Ref* pTarget, Node * pNode, const char* pSelectorName);
    
    virtual void onExit();
    virtual bool onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode);
    virtual void onNodeLoaded(Node * pNode, cocosbuilder::NodeLoader * pNodeLoader);
    
public:
    //control button call back
//    void onControlButtonClicked(cocos2d::Object * pSender, cocosbuilder::CCControlEvent pCCControlEvent);
    void onMenuItemClicked(cocos2d::Ref * pSender);
protected:
    cocos2d::Dictionary       *m_rViewDiction; //<name,CCObject*>
    std::map<std::string, int>    m_rMethodArray; //<CCObject*,secondKey>
    cocosbuilder::CCBAnimationManager         *m_hAnimationManager;
    int                           m_nAnimHandle;    //animation handle for lua script
    std::string                  m_sCCBName;
};


class luaCCBLayer
: public cocos2d::Layer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(luaCCBLayer, create);
};

class luaCCBLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(luaCCBLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(luaCCBLayer);
};


#endif
