//
//  DeapthScrollView.cpp
//  startcraft
//
//  Created by pizzaman on 25/05/2018.
//
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

#include "DeapthScrollView.hpp"

DeapthScrollView::DeapthScrollView()
{
    
}

DeapthScrollView::~DeapthScrollView()
{
    
}

DeapthScrollView* DeapthScrollView::create(Size size, Node* container/* = nullptr*/)
{
    DeapthScrollView* pRet = new (std::nothrow) DeapthScrollView();
    //增加前景layer和后景layer
    if (pRet && pRet->initWithViewSize(size, container))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

DeapthScrollView* DeapthScrollView::create()
{
    DeapthScrollView* pRet = new (std::nothrow) DeapthScrollView();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

bool DeapthScrollView::initWithViewSize(cocos2d::Size size,Node* container)
{
    frontLayer = Layer::create();
    frontLayer->setIgnoreAnchorPointForPosition(false);
    frontLayer->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(frontLayer,0,"frontLayer");
    backLayer = Layer::create();
    backLayer->setIgnoreAnchorPointForPosition(false);
    backLayer->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(backLayer,0,"backLayer");
    return ScrollView::initWithViewSize(size,container);
}

void DeapthScrollView::setContentOffset(cocos2d::Vec2 offset, bool animated)
{
    ScrollView::setContentOffset(offset,animated);
    if (m_nScriptHandler != 0){
        offset = this->getContentOffset();
        cocos2d::LuaStack * luaState = cocos2d::LuaEngine::getInstance()->getLuaStack();
        lua_State* m_state = luaState->getLuaState();
        luaState->clean();
        luaState->pushObject(this, "DeapthScrollView");
        vec2_to_luaval(m_state, offset);
        luaState->executeFunctionByHandler(m_nScriptHandler, 1);
    }
}

void DeapthScrollView::registerHandler(cocos2d::LUA_FUNCTION handler)
{
    unregisterHandler();
    m_nScriptHandler = handler;
}

void DeapthScrollView::unregisterHandler()
{
    if (m_nScriptHandler)
    {
        cocos2d::ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nScriptHandler);
        m_nScriptHandler = 0;
    }
}

void DeapthScrollView::addFrontLayerChild(cocos2d::Node *child, int zOrder, const std::string &name)
{
    frontLayer->addChild(child,zOrder,name);
}

void DeapthScrollView::addBackLayerChild(cocos2d::Node *child, int zOrder, const std::string &name)
{
    backLayer->addChild(child,zOrder,name);
}

void DeapthScrollView::addContainderChild(cocos2d::Node *child, int zOrder, const std::string &name)
{
    cocos2d::Node* no = this->getContainer();
    no->addChild(child, zOrder, name);
}

void DeapthScrollView::addChild(cocos2d::Node *child, int zOrder, int tag)
{
    Layer::addChild(child, zOrder, tag);
}

void DeapthScrollView::addChild(cocos2d::Node *child, int zOrder, const std::string &name)
{
    Layer::addChild(child, zOrder, name);
}

void DeapthScrollView::removeAllChildrenWithCleanup(bool cleanup)
{
    frontLayer->removeAllChildrenWithCleanup(cleanup);
    backLayer->removeAllChildrenWithCleanup(cleanup);
    ScrollView::removeAllChildrenWithCleanup(cleanup);
}

void DeapthScrollView::removeAllChildren()
{
    this->removeAllChildrenWithCleanup(true);
}

void DeapthScrollView::removeChild(Node* node, bool cleanup)
{
    Layer::removeChild(node, cleanup);
}

cocos2d::Layer* DeapthScrollView::getFrontLayer()
{
    return frontLayer;
}

cocos2d::Layer* DeapthScrollView::getBackLayer()
{
    return backLayer;
}
