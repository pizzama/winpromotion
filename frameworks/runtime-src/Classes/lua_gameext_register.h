#ifndef __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_GAMEEXT_REGISTER_H__
#define __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_GAMEEXT_REGISTER_H__

#include "auto/lua_luaccb_auto.hpp"
#include "auto/lua_game_ext_auto.hpp"

int lua_gameext_register(lua_State* L)
{
    register_all_luaccb(L);
    register_all_gameext(L);
    return 0;
}

#endif  // __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

