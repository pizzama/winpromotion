/*
** Lua binding: DeapthScrollView
** Generated automatically by tolua++-1.0.93-lua53 on Fri May 25 20:18:48 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "DeapthScrollView.hpp"
#include "cocos-ext.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

/* Exported function */
TOLUA_API int  tolua_DeapthScrollView_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Size");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"DeapthScrollView");
 tolua_usertype(tolua_S,"cocos2d::LUA_FUNCTION");
 tolua_usertype(tolua_S,"cocos2d::extension::ScrollView");
}

/* method: create of class  DeapthScrollView */
#ifndef TOLUA_DISABLE_tolua_DeapthScrollView_DeapthScrollView_create00
static int tolua_DeapthScrollView_DeapthScrollView_create00(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isusertable(tolua_S,1,"DeapthScrollView",0,&tolua_err))
     goto tolua_lerror;
 else
#endif
 {
     argc = lua_gettop(tolua_S)-1;
     do
     {
         if (argc == 0)
         {
//             cocos2d::extension::ScrollView* ret = DeapthScrollView::create();
//             object_to_luaval<DeapthScrollView>(tolua_S, "DeapthScrollView",(DeapthScrollView*)ret);
             return 1;
         }
     } while (0);
     ok  = true;
     do
     {
         if (argc == 1)
         {
             cocos2d::Size arg0;
             ok &= luaval_to_size(tolua_S, 2, &arg0, "DeapthScrollView:create");
             if (!ok) { break; }
             DeapthScrollView* ret = DeapthScrollView::create(arg0);
             object_to_luaval<DeapthScrollView>(tolua_S, "DeapthScrollView",(DeapthScrollView*)ret);
             return 1;
         }
     } while (0);
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerHandler of class  DeapthScrollView */
#ifndef TOLUA_DISABLE_tolua_DeapthScrollView_DeapthScrollView_registerHandler00
static int tolua_DeapthScrollView_DeapthScrollView_registerHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DeapthScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"cocos2d::LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DeapthScrollView* self = (DeapthScrollView*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::LUA_FUNCTION handler = *((cocos2d::LUA_FUNCTION*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerHandler'", NULL);
#endif
  {
   self->registerHandler(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterHandler of class  DeapthScrollView */
#ifndef TOLUA_DISABLE_tolua_DeapthScrollView_DeapthScrollView_unregisterHandler00
static int tolua_DeapthScrollView_DeapthScrollView_unregisterHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DeapthScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DeapthScrollView* self = (DeapthScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterHandler'", NULL);
#endif
  {
   self->unregisterHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_DeapthScrollView_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"DeapthScrollView","DeapthScrollView","cocos2d::extension::ScrollView",NULL);
  tolua_beginmodule(tolua_S,"DeapthScrollView");
   tolua_function(tolua_S,"create",tolua_DeapthScrollView_DeapthScrollView_create00);
   tolua_function(tolua_S,"registerHandler",tolua_DeapthScrollView_DeapthScrollView_registerHandler00);
   tolua_function(tolua_S,"unregisterHandler",tolua_DeapthScrollView_DeapthScrollView_unregisterHandler00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_DeapthScrollView (lua_State* tolua_S) {
 return tolua_DeapthScrollView_open(tolua_S);
};
#endif

