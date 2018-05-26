local mainscene_view = class("mainsceneView",__G_REQUIRE("app.like_oo.oo_sceneBase"));

function mainscene_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function mainscene_view:onCreate(  )
	local visibleSize = cc.Director:sharedDirector():getVisibleSize();
	local scrollViewSize = CCSizeMake(visibleSize.width,visibleSize.height)
	local scrollView = cc.ScrollView:create(scrollViewSize)
	scrollView:setAnchorPoint(cc.p(0.5, 0.5))
	scrollView:ignoreAnchorPointForPosition(false)
	scrollView:setPosition(visibleSize.width*0.5,visibleSize.height*0.5)
	scrollView:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL)

	local sp2 = cc.Sprite:create("background/homebg4.png");
	local size = sp2:getContentSize();
	sp2:setPosition(cc.p(size.width/2,size.height))
	scrollView:addChild(sp2)
	
	local sp1 = cc.Sprite:create("background/homebg1.png");
	local size = sp1:getContentSize();
	sp1:setPosition(cc.p(size.width*0.5,size.height*0.3))
	scrollView:setContentSize(size);
	scrollView:addChild(sp1);
	scrollView:setBounceable(false);
	scrollView:setContentOffset(cc.p(-size.width*0.3,size.height*0.5))

	self.m_rootView:addChild(scrollView)
end

function mainscene_view:onEnter(  )
	-- body
end

return mainscene_view;