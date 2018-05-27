#include "scripting/lua-bindings/auto/lua_game_ext_auto.hpp"
#include "DeapthScrollView.hpp"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_gameext_DeapthScrollView_getFrontLayer(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_getFrontLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_getFrontLayer'", nullptr);
            return 0;
        }
        cocos2d::Layer* ret = cobj->getFrontLayer();
        object_to_luaval<cocos2d::Layer>(tolua_S, "cc.Layer",(cocos2d::Layer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:getFrontLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_getFrontLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_initWithViewSize(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_initWithViewSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "DeapthScrollView:initWithViewSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_initWithViewSize'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithViewSize(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Size arg0;
        cocos2d::Node* arg1;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "DeapthScrollView:initWithViewSize");

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1, "DeapthScrollView:initWithViewSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_initWithViewSize'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithViewSize(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:initWithViewSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_initWithViewSize'.",&tolua_err);
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
int lua_gameext_DeapthScrollView_addFrontLayerChild(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_addFrontLayerChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        int arg1;
        std::string arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "DeapthScrollView:addFrontLayerChild");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "DeapthScrollView:addFrontLayerChild");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "DeapthScrollView:addFrontLayerChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_addFrontLayerChild'", nullptr);
            return 0;
        }
        cobj->addFrontLayerChild(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:addFrontLayerChild",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_addFrontLayerChild'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_addBackLayerChild(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_addBackLayerChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        int arg1;
        std::string arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "DeapthScrollView:addBackLayerChild");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "DeapthScrollView:addBackLayerChild");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "DeapthScrollView:addBackLayerChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_addBackLayerChild'", nullptr);
            return 0;
        }
        cobj->addBackLayerChild(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:addBackLayerChild",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_addBackLayerChild'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_getBackLayer(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_getBackLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_getBackLayer'", nullptr);
            return 0;
        }
        cocos2d::Layer* ret = cobj->getBackLayer();
        object_to_luaval<cocos2d::Layer>(tolua_S, "cc.Layer",(cocos2d::Layer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:getBackLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_getBackLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_gameext_DeapthScrollView_addContainderChild(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_gameext_DeapthScrollView_addContainderChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        int arg1;
        std::string arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "DeapthScrollView:addContainderChild");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "DeapthScrollView:addContainderChild");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "DeapthScrollView:addContainderChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_gameext_DeapthScrollView_addContainderChild'", nullptr);
            return 0;
        }
        cobj->addContainderChild(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DeapthScrollView:addContainderChild",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_gameext_DeapthScrollView_addContainderChild'.",&tolua_err);
#endif

    return 0;
}
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
        LUA_FUNCTION arg0 = (  toluafix_ref_function(tolua_S,2,0));
//        int arg0;
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
        tolua_function(tolua_S,"getFrontLayer",lua_gameext_DeapthScrollView_getFrontLayer);
        tolua_function(tolua_S,"initWithViewSize",lua_gameext_DeapthScrollView_initWithViewSize);
        tolua_function(tolua_S,"unregisterHandler",lua_gameext_DeapthScrollView_unregisterHandler);
        tolua_function(tolua_S,"addFrontLayerChild",lua_gameext_DeapthScrollView_addFrontLayerChild);
        tolua_function(tolua_S,"addBackLayerChild",lua_gameext_DeapthScrollView_addBackLayerChild);
        tolua_function(tolua_S,"getBackLayer",lua_gameext_DeapthScrollView_getBackLayer);
        tolua_function(tolua_S,"addContainderChild",lua_gameext_DeapthScrollView_addContainderChild);
        tolua_function(tolua_S,"registerHandler",lua_gameext_DeapthScrollView_registerHandler);
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

