local mainscene_main_view = class("mainscene_main_View",__G_REQUIRE("app.like_oo.oo_popBase"));

function mainscene_main_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function mainscene_main_view:onCreate(  )
	local ccbNode = cc.luaCCBNode:create();
	local function mainHandler(target,event)
		local tagNode = tolua.cast(target, "cc.Node")
		local btnTag  = tagNode:getTag()
		cclog("click:" .. tostring(btnTag))
		self:updateMsg(btnTag)
	end
	ccbNode:registerFunctionWithFuncName("mainHandler",mainHandler);
	ccbNode:openCCBFile("ccb/main_scene.ccbi");
	self.m_rootView:addChild(ccbNode)
end

function mainscene_main_view:onEnter(  )
	-- body
end

return mainscene_main_view;