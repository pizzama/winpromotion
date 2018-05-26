
cc.FileUtils:getInstance():setPopupNotify(false)

--加载默认的全局函数
package.path = package.path .. ";src/?.lua"
require('gfunc')
--加载需要的全局功能
__G_REQUIRE("cocos.init")
__G_REQUIRE("cocos.framework.init")
__G_REQUIRE("config")

--是否启动luadebug调试
if DEBUG_LUADEBUG then
    __G_REQUIRE("lua_debugger.debugger_main")
end

local function addSearchPath()
    local res_path = {}
    table.insert(res_path,"res")
    table.insert(res_path,"res/anim")
    local len = #res_path
    local writablePath = cc.FileUtils:getInstance():getWritablePath()
    cc.FileUtils:getInstance():addSearchPath(writablePath,true)
    local prefix_path = {writablePath,""}
    local count = #prefix_path
    for j=1,count do
        local prefix = prefix_path[j]
        for i=1,len do
            local path = prefix..res_path[i]
            cc.FileUtils:getInstance():addSearchPath(path)
        end 
    end
end

cc.FileUtils:getInstance():setPopupNotify(false)
local function main()
    addSearchPath()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
	local game = __G_REQUIRE("app.game").new()
	game:run()
end

xpcall(main, __G__TRACKBACK__)
