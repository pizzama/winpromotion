local login_view = class("loginView",__G_REQUIRE("app.like_oo.oo_sceneBase"));

function login_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function login_view:onCreate(  )
	local ccbNode = cc.luaCCBNode:create();
	local function mainHandler(target,event)
		local tagNode = tolua.cast(target, "cc.Node")
		local btnTag  = tagNode:getTag()
		cclog("click:" .. tostring(btnTag))
		self:updateMsg(btnTag)
	end
	ccbNode:registerFunctionWithFuncName("mainHandler",mainHandler);
	ccbNode:openCCBFile("ccb/login_scene.ccbi");
	--主标志上下移动
	local title = ccbNode:spriteForName("title");
	local posx,posy = title:getPosition();
	local act = CCMoveBy:create(2,cc.p(0, 20))
	title:runAction(cc.RepeatForever:create(cc.Sequence:create({act,act:reverse()})))

	--更换选区按钮
	local changeBtn = ccbNode:controlButtonForName("changeBtn")
	changeBtn:setOpacity(0);

	self.m_rootView:addChild(ccbNode)
end

function login_view:onEnter(  )
	-- body
end

return login_view;