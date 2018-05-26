local selectserver_view = class("selectserverView",__G_REQUIRE("app.like_oo.oo_popBase"));

function selectserver_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function selectserver_view:onCreate(  )
	local ccbNode = cc.luaCCBNode:create();
	local function mainHandler(target,event)
		local tagNode = tolua.cast(target, "cc.Node")
		local btnTag  = tagNode:getTag()
		cclog("click:" .. tostring(btnTag))
		if btnTag == 1 then

		elseif btnTag == 2 then
			
		end
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

function selectserver_view:onEnter(  )
	-- body
end

return selectserver_view;