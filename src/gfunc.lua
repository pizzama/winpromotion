__g_load_lua_table = {}--存放require的文件，用于清除package.loaded中的缓存

--[[
    游戏逻辑使用的模块使用此方法加载，系统或引擎方法不用
]]
function __G_REQUIRE(moduleName)
    if __g_load_lua_table[moduleName] == nil then
        __g_load_lua_table[moduleName] = 1
    end
    return require(moduleName)
end

function __G__TRACKBACK__(msg)
    local cclog = cclog or print
    local info = "LUA ERROR: " .. tostring(msg) .. "\n"..debug.traceback("", 2)
    if DEBUG > 1 then
        cclog(info)
        if luaDebuggerXpCall then
            luaDebuggerXpCall(msg)
        end
        -- if device then
        --     device.showAlert( "error", info, "ok", function ()
        --     end)
        -- end
    end

end

--[[
    在游戏中重新登录时有资源下载，需要清除缓存的lua
]]
function __G_PURGEPACKAGELOADED()
    for k,v in pairs(__g_load_lua_table) do
        package.loaded[k] = nil
    end
end

function __G_RELOAD( moduleName )
    package.loaded[moduleName] = nil
    return require(moduleName)
end