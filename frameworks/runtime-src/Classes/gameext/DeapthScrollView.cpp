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

void DeapthScrollView::setContentOffset(cocos2d::Vec2 offset, bool animated)
{
    ScrollView::setContentOffset(offset,animated);
    cocos2d::LuaStack * luaState = cocos2d::LuaEngine::getInstance()->getLuaStack();
    lua_State* m_state = luaState->getLuaState();
    luaState->clean();
    luaState->pushObject(this, "DeapthScrollView");
    vec2_to_luaval(m_state, offset);
    luaState->executeFunctionByHandler(m_nScriptHandler, 1);
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

bool DeapthScrollView::onTouchBegan(Touch* touch, Event* event)
{
    return ScrollView::onTouchBegan(touch, event);
}

void DeapthScrollView::onTouchMoved(Touch* touch, Event* event)
{
    ScrollView::onTouchMoved(touch, event);
}

void DeapthScrollView::onTouchEnded(Touch* touch, Event* event)
{
    ScrollView::onTouchEnded(touch, event);
}

void DeapthScrollView::onTouchCancelled(Touch* touch, Event* event)
{
    ScrollView::onTouchCancelled(touch, event);
}
