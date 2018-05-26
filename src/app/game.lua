--[[
	游戏全局控制类
--]]
local game = class("game", __G_REQUIRE("packages.mvc.AppBase"))

--需要加载的全局控制器
scheduler = __G_REQUIRE("app.shared.scheduler")
game_url = __G_REQUIRE("app.game_url_config")
util = __G_REQUIRE("app.shared.util")

--加载游戏需要的全局配置
__G_REQUIRE("app.game_version_config")


function game:ctor()
    game.super.ctor(self)
    rootController = __G_REQUIRE("app.like_oo.oo_controlBase")
    __G_REQUIRE("app.shared.log")
end

--初始化需要的资源目录
function game:initResourceNeed()
	VISIBLE_SIZE = CCDirector:sharedDirector():getVisibleSize()
end
--初始化语言
function game:languageInit()
    print("--languageInit---")
end

-- 初始化之前
function game:beforeInit()

end
-- 内容
function game:initGame()

end
-- 运行
function game:run()
    __G_PURGEPACKAGELOADED()
	rootController:openView("update")
end


--更包 删除本地资源
function game:checkClienVer()

end

-- 重新开始
function game:reStartGame()

end

function game:checkUpdate()

end

return game