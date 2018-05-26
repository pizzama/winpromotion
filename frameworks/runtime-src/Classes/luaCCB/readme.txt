luaCCBLayer

本扩展是为了满足在lua中使用ccbi资源而添加的

扩展类文件：
luaCCBLayer.h
luaCCBLayer.cpp

lua++生成文件：
luaCCBNode.pkg
注意：
		生成cpp后需要修改lua++工具对registerFunctionWithFuncName函数的解释
		将： if (
     !tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
  	修改成： if (
     !tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S, 3, &tolua_err) || !toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, &tolua_err))   ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
  	将：int handle = ((int)  tolua_tonumber(tolua_S,3,0));
  	修改成：int handle = toluafix_ref_function(tolua_S, 3, 0);
		原因：原有表达会判断第二个参数是否是整形，而我们实际需要的是一个lua的函数id
		

修改系统原有文件：
extension/GUI/ControlExtension/CCInvocation.h
extension/GUI/ControlExtension/CCInvocation.cpp

		修改：CCInvocation.h中类CCInvocation添加静态函数static void usedScript(bool used);
		修改：CCInvocation.cpp文件中添加全局变量static bool kGlobalScriptFlag;
					实现函数usedScript
					void CCInvocation::usedScript(bool used)
					{
 					   kGlobalScriptFlag = used;
					}
				将
				void CCInvocation::invoke(CCObject* sender)
				{
    				if (m_target && m_action)
    				{
            		(m_target->*m_action)(sender, m_controlEvent);
    				}                
				}
				修改为
				void CCInvocation::invoke(CCObject* sender)
				{
    				if (m_target && m_action)
    				{
       				 //add this, it is used call lua function
        				if(kGlobalScriptFlag)
       				 {
           				 CCLuaEngine *luaEngine;
         	  			 luaEngine = (CCLuaEngine*)CCScriptEngineManager::sharedManager()->getScriptEngine();
           				 //int luaId = (int)m_action;
            			 int id=*((int*)(&m_action));
           				 luaEngine->cleanStack();
            			 luaEngine->pushCCObject(sender, "CCObject");
            			 luaEngine->pushInt(m_controlEvent);
            			 luaEngine->executeFunctionByHandler(id, 2);
				        }
				        else 
				            (m_target->*m_action)(sender, m_controlEvent);
				    }                
				}
				如果标志kGlobalScriptFlag为true则通过已经注册的id调用lua函数