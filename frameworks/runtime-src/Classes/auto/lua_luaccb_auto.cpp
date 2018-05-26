#include "lua_luaccb_auto.hpp"
#include "luaCCBLayer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"




int lua_luaccb_luaCCBNode_registerFunctionWithFuncName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_registerFunctionWithFuncName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
//        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:registerFunctionWithFuncName"); arg0 = arg0_tmp.c_str();

//        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "luaCCBNode:registerFunctionWithFuncName");
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_registerFunctionWithFuncName'", nullptr);
//            return 0;
//        }
        int arg1 = toluafix_ref_function(tolua_S, 3, 0);
        bool ret = cobj->registerFunctionWithFuncName(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:registerFunctionWithFuncName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_registerFunctionWithFuncName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_layerColorForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_layerColorForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:layerColorForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_layerColorForName'", nullptr);
            return 0;
        }
        cocos2d::LayerColor* ret = cobj->layerColorForName(arg0);
        object_to_luaval<cocos2d::LayerColor>(tolua_S, "cc.LayerColor",(cocos2d::LayerColor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:layerColorForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_layerColorForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_objectForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_objectForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:objectForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_objectForName'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->objectForName(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:objectForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_objectForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_openCCBFile(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_openCCBFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:openCCBFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_openCCBFile'", nullptr);
            return 0;
        }
        bool ret = cobj->openCCBFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:openCCBFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_openCCBFile'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_registerAnimFunc(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_registerAnimFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        //        int arg0;
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        ScriptHandlerMgr::HandlerType handlerType = (ScriptHandlerMgr::HandlerType) ((int)tolua_tonumber(tolua_S,3,0) + (int)ScriptHandlerMgr::HandlerType::CALLFUNC);
        
        ScriptHandlerMgr::getInstance()->addObjectHandler((void*)cobj, handler, handlerType);
        //        if(!ok)
        //        {
        //            tolua_error(tolua_S,"invalid arguments in function 'lua_game_ext_zcAnimNode_registerScriptTapHandler'", nullptr);
        //            return 0;
        //        }
        //        cobj->registerScriptTapHandler(arg0);
        return 0;
    }
//    argc = lua_gettop(tolua_S)-1;
//    if (argc == 1) 
//    {
//        int arg0;
//
//        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "luaCCBNode:registerAnimFunc");
//        if(!ok)
//        {
//            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_registerAnimFunc'", nullptr);
//            return 0;
//        }
//        bool ret = cobj->registerAnimFunc(arg0);
//        tolua_pushboolean(tolua_S,(bool)ret);
//        return 1;
//    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:registerAnimFunc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_registerAnimFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_completedAnimationSequenceNamed(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_completedAnimationSequenceNamed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:completedAnimationSequenceNamed"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_completedAnimationSequenceNamed'", nullptr);
            return 0;
        }
        cobj->completedAnimationSequenceNamed(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:completedAnimationSequenceNamed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_completedAnimationSequenceNamed'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_onNodeLoaded(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_onNodeLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        cocosbuilder::NodeLoader* arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_object<cocosbuilder::NodeLoader>(tolua_S, 3, "cc.NodeLoader",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_onNodeLoaded'", nullptr);
            return 0;
        }
        cobj->onNodeLoaded(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:onNodeLoaded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_onNodeLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_controlButtonForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_controlButtonForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:controlButtonForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_controlButtonForName'", nullptr);
            return 0;
        }
        cocos2d::extension::ControlButton* ret = cobj->controlButtonForName(arg0);
        object_to_luaval<cocos2d::extension::ControlButton>(tolua_S, "cc.ControlButton",(cocos2d::extension::ControlButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:controlButtonForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_controlButtonForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_labelBMFontForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_labelBMFontForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:labelBMFontForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_labelBMFontForName'", nullptr);
            return 0;
        }
        cocos2d::Label* ret = cobj->labelBMFontForName(arg0);
        object_to_luaval<cocos2d::Label>(tolua_S, "cc.Label",(cocos2d::Label*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:labelBMFontForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_labelBMFontForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_unregisterFunctionWithFuncName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_unregisterFunctionWithFuncName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:unregisterFunctionWithFuncName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_unregisterFunctionWithFuncName'", nullptr);
            return 0;
        }
        cobj->unregisterFunctionWithFuncName(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:unregisterFunctionWithFuncName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_unregisterFunctionWithFuncName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_init(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_init'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_particleForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_particleForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:particleForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_particleForName'", nullptr);
            return 0;
        }
        cocos2d::ParticleSystemQuad* ret = cobj->particleForName(arg0);
        object_to_luaval<cocos2d::ParticleSystemQuad>(tolua_S, "cc.ParticleSystemQuad",(cocos2d::ParticleSystemQuad*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:particleForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_particleForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_scale9SpriteForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_scale9SpriteForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:scale9SpriteForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_scale9SpriteForName'", nullptr);
            return 0;
        }
        cocos2d::ui::Scale9Sprite* ret = cobj->scale9SpriteForName(arg0);
        object_to_luaval<cocos2d::ui::Scale9Sprite>(tolua_S, "ccui.Scale9Sprite",(cocos2d::ui::Scale9Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:scale9SpriteForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_scale9SpriteForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_scrollViewForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_scrollViewForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:scrollViewForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_scrollViewForName'", nullptr);
            return 0;
        }
        cocos2d::extension::ScrollView* ret = cobj->scrollViewForName(arg0);
        object_to_luaval<cocos2d::extension::ScrollView>(tolua_S, "cc.ScrollView",(cocos2d::extension::ScrollView*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:scrollViewForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_scrollViewForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_spriteForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_spriteForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:spriteForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_spriteForName'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->spriteForName(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:spriteForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_spriteForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_labelTTFForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_labelTTFForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:labelTTFForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_labelTTFForName'", nullptr);
            return 0;
        }
        cocos2d::Label* ret = cobj->labelTTFForName(arg0);
        object_to_luaval<cocos2d::Label>(tolua_S, "cc.Label",(cocos2d::Label*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:labelTTFForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_labelTTFForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_onMenuItemClicked(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_onMenuItemClicked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_onMenuItemClicked'", nullptr);
            return 0;
        }
        cobj->onMenuItemClicked(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:onMenuItemClicked",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_onMenuItemClicked'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_unregisterAnimFunc(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_unregisterAnimFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_unregisterAnimFunc'", nullptr);
            return 0;
        }
        cobj->unregisterAnimFunc();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:unregisterAnimFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_unregisterAnimFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_runAnimations(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_runAnimations'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:runAnimations"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->runAnimations(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:runAnimations"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "luaCCBNode:runAnimations");

            if (!ok) { break; }
            cobj->runAnimations(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "luaCCBNode:runAnimations",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_runAnimations'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_nodeForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_nodeForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:nodeForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_nodeForName'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->nodeForName(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:nodeForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_nodeForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_layerGradientForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_layerGradientForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:layerGradientForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_layerGradientForName'", nullptr);
            return 0;
        }
        cocos2d::LayerGradient* ret = cobj->layerGradientForName(arg0);
        object_to_luaval<cocos2d::LayerGradient>(tolua_S, "cc.LayerGradient",(cocos2d::LayerGradient*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:layerGradientForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_layerGradientForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_layerForName(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_layerForName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:layerForName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_layerForName'", nullptr);
            return 0;
        }
        cocos2d::Layer* ret = cobj->layerForName(arg0);
        object_to_luaval<cocos2d::Layer>(tolua_S, "cc.Layer",(cocos2d::Layer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:layerForName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_layerForName'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_onAssignCCBMemberVariable(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (luaCCBNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_luaccb_luaCCBNode_onAssignCCBMemberVariable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Ref* arg0;
        const char* arg1;
        cocos2d::Node* arg2;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "luaCCBNode:onAssignCCBMemberVariable"); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 4, "cc.Node",&arg2);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_onAssignCCBMemberVariable'", nullptr);
            return 0;
        }
        bool ret = cobj->onAssignCCBMemberVariable(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:onAssignCCBMemberVariable",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_onAssignCCBMemberVariable'.",&tolua_err);
#endif

    return 0;
}
int lua_luaccb_luaCCBNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_create'", nullptr);
            return 0;
        }
        luaCCBNode* ret = luaCCBNode::create();
        object_to_luaval<luaCCBNode>(tolua_S, "luaCCBNode",(luaCCBNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "luaCCBNode:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_luaccb_luaCCBNode_addPublicResource(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"luaCCBNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "luaCCBNode:addPublicResource"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_addPublicResource'", nullptr);
            return 0;
        }
        luaCCBNode::addPublicResource(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "luaCCBNode:addPublicResource",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_addPublicResource'.",&tolua_err);
#endif
    return 0;
}
int lua_luaccb_luaCCBNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    luaCCBNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_luaccb_luaCCBNode_constructor'", nullptr);
            return 0;
        }
        cobj = new luaCCBNode();
        tolua_pushusertype(tolua_S,(void*)cobj,"luaCCBNode");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "luaCCBNode:luaCCBNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_luaccb_luaCCBNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_luaccb_luaCCBNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (luaCCBNode)");
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (
    !tolua_isusertype(tolua_S,1,"luaCCBNode",0,&tolua_err) ||
    !tolua_isnoobj(tolua_S,2,&tolua_err)
    )
        goto tolua_lerror;
    else
#endif
    {
        luaCCBNode* self = (luaCCBNode*)  tolua_tousertype(tolua_S,1,0);
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

int lua_register_luaccb_luaCCBNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"luaCCBNode");
    tolua_cclass(tolua_S,"luaCCBNode","luaCCBNode","cc.Node",lua_luaccb_luaCCBNode_finalize);

    tolua_beginmodule(tolua_S,"luaCCBNode");
        tolua_function(tolua_S,"new",lua_luaccb_luaCCBNode_constructor);
        tolua_function(tolua_S,"registerFunctionWithFuncName",lua_luaccb_luaCCBNode_registerFunctionWithFuncName);
        tolua_function(tolua_S,"layerColorForName",lua_luaccb_luaCCBNode_layerColorForName);
        tolua_function(tolua_S,"objectForName",lua_luaccb_luaCCBNode_objectForName);
        tolua_function(tolua_S,"openCCBFile",lua_luaccb_luaCCBNode_openCCBFile);
        tolua_function(tolua_S,"registerAnimFunc",lua_luaccb_luaCCBNode_registerAnimFunc);
        tolua_function(tolua_S,"completedAnimationSequenceNamed",lua_luaccb_luaCCBNode_completedAnimationSequenceNamed);
        tolua_function(tolua_S,"onNodeLoaded",lua_luaccb_luaCCBNode_onNodeLoaded);
        tolua_function(tolua_S,"controlButtonForName",lua_luaccb_luaCCBNode_controlButtonForName);
        tolua_function(tolua_S,"labelBMFontForName",lua_luaccb_luaCCBNode_labelBMFontForName);
        tolua_function(tolua_S,"unregisterFunctionWithFuncName",lua_luaccb_luaCCBNode_unregisterFunctionWithFuncName);
        tolua_function(tolua_S,"init",lua_luaccb_luaCCBNode_init);
        tolua_function(tolua_S,"particleForName",lua_luaccb_luaCCBNode_particleForName);
        tolua_function(tolua_S,"scale9SpriteForName",lua_luaccb_luaCCBNode_scale9SpriteForName);
        tolua_function(tolua_S,"scrollViewForName",lua_luaccb_luaCCBNode_scrollViewForName);
        tolua_function(tolua_S,"spriteForName",lua_luaccb_luaCCBNode_spriteForName);
        tolua_function(tolua_S,"labelTTFForName",lua_luaccb_luaCCBNode_labelTTFForName);
        tolua_function(tolua_S,"onMenuItemClicked",lua_luaccb_luaCCBNode_onMenuItemClicked);
        tolua_function(tolua_S,"unregisterAnimFunc",lua_luaccb_luaCCBNode_unregisterAnimFunc);
        tolua_function(tolua_S,"runAnimations",lua_luaccb_luaCCBNode_runAnimations);
        tolua_function(tolua_S,"nodeForName",lua_luaccb_luaCCBNode_nodeForName);
        tolua_function(tolua_S,"layerGradientForName",lua_luaccb_luaCCBNode_layerGradientForName);
        tolua_function(tolua_S,"layerForName",lua_luaccb_luaCCBNode_layerForName);
        tolua_function(tolua_S,"onAssignCCBMemberVariable",lua_luaccb_luaCCBNode_onAssignCCBMemberVariable);
        tolua_function(tolua_S,"create", lua_luaccb_luaCCBNode_create);
        tolua_function(tolua_S,"addPublicResource", lua_luaccb_luaCCBNode_addPublicResource);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(luaCCBNode).name();
    g_luaType[typeName] = "luaCCBNode";
//    g_typeCast["luaCCBNode"] = "luaCCBNode";
    return 1;
}
TOLUA_API int register_all_luaccb(lua_State* tolua_S)
{
    lua_getglobal(tolua_S, "_G");
    if (lua_istable(tolua_S,-1))//stack:...,_G,
    {
        tolua_open(tolua_S);
        
        tolua_module(tolua_S,"cc",0);
        tolua_beginmodule(tolua_S,"cc");
        
        lua_register_luaccb_luaCCBNode(tolua_S);
        
        tolua_endmodule(tolua_S);
    }
    lua_pop(tolua_S, 1);
	return 1;
}

