//
//  NDKCallbackNode.h
//  EasyNDK-for-cocos2dx
//
//  Created by Amir Ali Jiwani on 23/02/2013.
//
//

#ifndef __EasyNDK_for_cocos2dx__NDKCallbackNode__
#define __EasyNDK_for_cocos2dx__NDKCallbackNode__

#include "cocos2d.h"
#include <string>
USING_NS_CC;
using namespace std;

class NDKCallbackNode
{
private :
    SEL_CallFuncND sel;
    string name;
    string groupName;
    Node *target;
    
    //for lua call back
    int    m_luaHandler;
    
public :
    
    NDKCallbackNode(const char *groupName, const char *name, SEL_CallFuncND sel, Node *target);
    NDKCallbackNode(const char *groupName, const char *name, int handler);
    ~NDKCallbackNode();
    
    string getName();
    string getGroup();
    SEL_CallFuncND getSelector();
    Node* getTarget();
    
    int getLuaHandler(){return m_luaHandler;}
    void registerScriptHandler(int handler);
    void unRegisterScriptHandler();
};

#endif /* defined(__EasyNDK_for_cocos2dx__NDKCallbackNode__) */
