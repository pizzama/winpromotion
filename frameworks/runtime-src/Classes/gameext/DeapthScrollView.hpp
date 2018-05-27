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
    virtual void setContentOffset(cocos2d::Vec2 offset, bool animated = false) override;
    void registerHandler(cocos2d::LUA_FUNCTION handler);
    void unregisterHandler();
    bool initWithViewSize(cocos2d::Size size, cocos2d::Node* container = NULL);
    virtual void addChild(Node * child, int zOrder, int tag) override;
    virtual void addChild(Node * child, int zOrder, const std::string &name) override;
    virtual void removeAllChildren() override;
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;
    virtual void removeChild(Node* child, bool cleanup = true) override;
    cocos2d::Layer* getFrontLayer();
    cocos2d::Layer* getBackLayer();
    void addFrontLayerChild(cocos2d::Node * child, int zOrder, const std::string &name);
    void addBackLayerChild(cocos2d::Node * child, int zOrder, const std::string &name);
    void addContainderChild(cocos2d::Node * child, int zOrder, const std::string &name);
private:
    cocos2d::Layer *frontLayer;
    cocos2d::Layer *backLayer;
    cocos2d::LUA_FUNCTION m_nScriptHandler=0;
};

#endif /* DeapthScrollView_hpp */
