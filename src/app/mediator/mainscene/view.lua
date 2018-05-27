local mainscene_view = class("mainsceneView",__G_REQUIRE("app.like_oo.oo_sceneBase"));
local sceneman = __G_REQUIRE("app.mediator.mainscene.sceneman")
function mainscene_view:onCommand( command , data )
	-- body
	--[[同步命令回调]]
end

function mainscene_view:onCreate(  )
	local visibleSize = cc.Director:sharedDirector():getVisibleSize();
	local scrollViewSize = CCSizeMake(visibleSize.width,visibleSize.height)
	local scrollView = pz.DeapthScrollView:create(scrollViewSize)
	scrollView:setAnchorPoint(cc.p(0.5, 0.5))
	scrollView:ignoreAnchorPointForPosition(false)
	scrollView:setPosition(visibleSize.width*0.5,visibleSize.height*0.5)
	scrollView:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL)

	--天空背景
	local sp2 = cc.Sprite:create("background/homebg4.png");
	local size = sp2:getContentSize();
	local sp2pos = cc.p(size.width/2,700)
	sp2:setPosition(sp2pos)
	scrollView:addBackLayerChild(sp2,0,"sp2")
	--山远景
	local sp3 = cc.Sprite:create("background/homebg3.png");
	local size = sp3:getContentSize();
	local sp3pos = cc.p(size.width/2,500)
	sp3:setPosition(sp3pos)
	scrollView:addBackLayerChild(sp3,0,"sp3")

	--山近景
	local sp4 = cc.Sprite:create("background/homebg2.png");
	local size = sp4:getContentSize();
	local sp4pos = cc.p(size.width/2,460)
	sp4:setPosition(sp4pos)
	scrollView:addBackLayerChild(sp4,0,"sp4")
	
	local sp1 = cc.Sprite:create("background/homebg1.png");
	local size = sp1:getContentSize();
	sp1:setPosition(cc.p(size.width*0.5,300))
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

		local p3 = cc.p(sp3pos.x + vec.x*0.3,sp3pos.y + vec.y)
		sp3:setPosition(p3)

		local p4 = cc.p(sp4pos.x + vec.x * 0.1,sp4pos.y + vec.y)
		sp4:setPosition(p4);

	end,1);
	self.m_rootView:addChild(scrollView)

	--增加管家和账房角色
	local man = sceneman.new("human/human2.png",cc.p(700,400));
	scrollView:addContainderChild(man,0,"man")
	local man1 = sceneman.new("human/human4.png",cc.p(500,400));
	scrollView:addContainderChild(man1,0,"man1")
end

function mainscene_view:onEnter(  )
	-- body
end

return mainscene_view;