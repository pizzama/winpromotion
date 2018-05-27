local cityscene_view = class("cityceneView",__G_REQUIRE("app.like_oo.oo_sceneBase"));

function cityscene_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function cityscene_view:onCreate(  )
	local visibleSize = cc.Director:sharedDirector():getVisibleSize();
	local scrollViewSize = CCSizeMake(visibleSize.width,visibleSize.height)
	local scrollView = pz.DeapthScrollView:create(scrollViewSize)
	scrollView:setAnchorPoint(cc.p(0.5, 0.5))
	scrollView:ignoreAnchorPointForPosition(false)
	scrollView:setPosition(visibleSize.width*0.5,visibleSize.height*0.5)
	scrollView:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL)

	--天空背景
	local sp2 = cc.Sprite:create("background/citybg3.jpg");
	local size = sp2:getContentSize();
	local sp2pos = cc.p(size.width/2,700)
	sp2:setPosition(sp2pos)
	scrollView:addBackLayerChild(sp2,0,"sp2")

	--山近景
	local sp4 = cc.Sprite:create("background/citybg2.png");
	local size = sp4:getContentSize();
	local sp4pos = cc.p(size.width/2,650)
	sp4:setPosition(sp4pos)
	scrollView:addBackLayerChild(sp4,0,"sp4")
	
	local sp1 = cc.Sprite:create("background/citybg1.png");
	local size = sp1:getContentSize();
	sp1:setPosition(cc.p(size.width*0.5,500))
	scrollView:setContentSize(size);
	scrollView:addContainderChild(sp1,0,"fa");
	scrollView:setBounceable(false);
	scrollView:setContentOffset(cc.p(-size.width*0.3,size.height*0.5))
	
	local curpos = cc.p(0,0)
	scrollView:scheduleUpdateWithPriorityLua(function()
		local vec = scrollView:getContentOffset();
		if curpos.x == vec.x and curpos.y == vec.y then
			return
		end
		curpos = vec;
		--设置背景的位移效果
		local p2 = cc.p(sp2pos.x + vec.x*0.4,sp2pos.y + vec.y*0.3)
		sp2:setPosition(p2);

		local p4 = cc.p(sp4pos.x + vec.x * 0.2,sp4pos.y + vec.y*0.2)
		sp4:setPosition(p4);

	end,1);
	self.m_rootView:addChild(scrollView)
end

function cityscene_view:onEnter(  )
	-- body
end

return cityscene_view;