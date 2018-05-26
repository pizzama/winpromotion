local ship = class("ship", __G_REQUIRE("app.ui.battle.steeredEntity"))
local vector2d = __G_REQUIRE("app.shared.vector2d");

function ship:ctor()
	ship.super.ctor(self)
	self.stagewidth = 960;
	self.stageheight = 640
	self:setNodeDirection(math.pi);
	self:draw();
end

function ship:draw()
	print("create draw:")
	local sp = CCSprite:create("buff_icon/buff_cause_shanghai.png");
	self:addChild(sp);
 --    local jsonFile = "ship/9996/10101_9996_D.json";
 --    local atlasFile = "ship/9996/9996.atlas";
	-- self.skdata = sp.SkeletonData:create(jsonFile,atlasFile)
	-- self.spk = sp.SkeletonAnimation:create(self.skdata)
	-- self.spk:setAnchorPoint(cc.p(0.5,0.5))
	-- self:addChild(self.spk)
	-- self.spk:setAnimation(0, "daiji", true)
end


return ship