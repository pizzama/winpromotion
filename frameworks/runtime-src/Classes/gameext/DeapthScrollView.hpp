//
//  DeapthScrollView.hpp
//  startcraft
//
//  Created by pizzaman on 25/05/2018.
//

#ifndef DeapthScrollView_hpp
#define DeapthScrollView_hpp

#include "GUI/CCScrollView/CCScrollView.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "base/CCEventListenerTouch.h"

class DeapthScrollView:public cocos2d::extension::ScrollView {
public:
    static DeapthScrollView* create(cocos2d::Size size, Node* container = NULL);
    static DeapthScrollView* create();
    DeapthScrollView();
    ~DeapthScrollView();
    //如需要把父类方法改成virtual，需要进行方法重载
    void setContentOffset(cocos2d::Vec2 offset, bool animated = false);
    void registerHandler(cocos2d::LUA_FUNCTION handler);
    void unregisterHandler();
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event) override;
private:
    cocos2d::LUA_FUNCTION m_nScriptHandler=0;
};

#endif /* DeapthScrollView_hpp */
