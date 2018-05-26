//
//  NDKCallbackNode.cpp
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#include "NDKCallbackNode.h"

NDKCallbackNode::NDKCallbackNode(const char *groupName, const char *name, SEL_CallFuncND sel, Node *target)
:m_luaHandler(0)
{
    this->groupName = groupName;
    this->name = name;
    this->sel = sel;
    this->target = target;
}

string NDKCallbackNode::getName()
{
    return this->name;
}

string NDKCallbackNode::getGroup()
{
    return this->groupName;
}

SEL_CallFuncND NDKCallbackNode::getSelector()
{
    return this->sel;
}

Node* NDKCallbackNode::getTarget()
{
    return this->target;
}

NDKCallbackNode::NDKCallbackNode(const char *groupName, const char *name, int handler)
:sel(NULL)
,target(NULL)
,m_luaHandler(0)
{
    this->groupName = groupName;
    this->name = name;
    this->m_luaHandler = handler;
}

void NDKCallbackNode::registerScriptHandler(int handler)
{
    unRegisterScriptHandler();
    m_luaHandler = handler;
}

void NDKCallbackNode::unRegisterScriptHandler()
{
    if (m_luaHandler > 0) {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_luaHandler);
        m_luaHandler = 0;
    }
}

NDKCallbackNode::~NDKCallbackNode()
{

}

