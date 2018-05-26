#include "scripting/lua-bindings/auto/lua_game_ext_auto.hpp"
#include "DeapthScrollView.hpp"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_gameext_DeapthScrollView_registerHandler(lua_State* tolua_S)
{
    int argc = 0;
    DeapthScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DeapthScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DeapthScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_registerHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
//        int arg0;
        LUA_FUNCTION arg0 = (  toluafix_ref_function(tolua_S,2,0));
//        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DeapthScrollView:registerHandler");
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_registerHandler'", nullptr);
//            return 0;
//        }
        cobj->registerHandler(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:registerHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_registerHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_unregisterHandler(lua_State* tolua_S)
{
    int argc = 0;
    DeapthScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DeapthScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DeapthScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_unregisterHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_unregisterHandler'", nullptr);
            return 0;
        }
        cobj->unregisterHandler();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:unregisterHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_unregisterHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_setContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    DeapthScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DeapthScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DeapthScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_setContentOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "DeapthScrollView:setContentOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_setContentOffset'", nullptr);
            return 0;
        }
        cobj->setContentOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Vec2 arg0;
        bool arg1;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "DeapthScrollView:setContentOffset");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "DeapthScrollView:setContentOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_setContentOffset'", nullptr);
            return 0;
        }
        cobj->setContentOffset(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:setContentOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_setContentOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DeapthScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 0)
        {
            DeapthScrollView* ret = DeapthScrollView::create();
            object_to_luaval<DeapthScrollView>(tolua_S, "DeapthScrollView",(DeapthScrollView*)ret);
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
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0, "DeapthScrollView:create");
            if (!ok) { break; }
            cocos2d::Node* arg1;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "DeapthScrollView:create");
            if (!ok) { break; }
            DeapthScrollView* ret = DeapthScrollView::create(arg0, arg1);
            object_to_luaval<DeapthScrollView>(tolua_S, "DeapthScrollView",(DeapthScrollView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "DeapthScrollView:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_gameext_DeapthScrollView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    DeapthScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_constructor'", nullptr);
            return 0;
        }
        cobj = new DeapthScrollView();
        tolua_pushusertype(tolua_S,(void*)cobj,"DeapthScrollView");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:DeapthScrollView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_gameext_DeapthScrollView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DeapthScrollView)");
#if COCOS2D_DEBUG >= 1
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
#if COCOS2D_DEBUG >= 1
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", nullptr);
#endif
        delete self;
    }
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
    return 0;
#endif
    return 0;
}

int lua_register_gameext_DeapthScrollView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DeapthScrollView");
    tolua_cclass(tolua_S,"DeapthScrollView","DeapthScrollView","cc.ScrollView",lua_gameext_DeapthScrollView_finalize);

    tolua_beginmodule(tolua_S,"DeapthScrollView");
        tolua_function(tolua_S,"new",lua_gameext_DeapthScrollView_constructor);
        tolua_function(tolua_S,"registerHandler",lua_gameext_DeapthScrollView_registerHandler);
        tolua_function(tolua_S,"unregisterHandler",lua_gameext_DeapthScrollView_unregisterHandler);
        tolua_function(tolua_S,"setContentOffset",lua_gameext_DeapthScrollView_setContentOffset);
        tolua_function(tolua_S,"create", lua_gameext_DeapthScrollView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DeapthScrollView).name();
    g_luaType[typeName] = "DeapthScrollView";
    g_typeCast["DeapthScrollView"] = "DeapthScrollView";
    return 1;
}
TOLUA_API int register_all_gameext(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
    tolua_module(tolua_S,"pz",0);
    tolua_beginmodule(tolua_S,"pz");

	lua_register_gameext_DeapthScrollView(tolua_S);

    tolua_endmodule(tolua_S);
	return 1;
}

