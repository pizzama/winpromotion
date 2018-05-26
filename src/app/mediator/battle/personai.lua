local personai = class("personai", __G_REQUIRE("app.ui.battle.person"))
local vector2d = __G_REQUIRE("app.shared.vector2d");
--定义人物持有武器
local weapon = {"Handgun","Rifle","Slash"}
local sightDist = {Handgun=300,Slash=100,Rifle=250}
function personai:ctor(parent,feature,totalscale)
	self.enemys = nil;
	self.maxHp = 1000
	self.curHp = 1000
	self.group = parent
	self.leader = false;
	--加载行为树
	self.tree = b3.BehaviorTree.new();
	self.blackboard = b3.Blackborad.new();
	local fileUtils = cc.FileUtils:getInstance()
    local fullpath = fileUtils:fullPathForFilename("res/ai/SingleMoveAI.json") 
    local data = json.decode( io.readfile(fullpath))
    self.tree:load(data)
	personai.super.ctor(self,feature,totalscale)
end

function personai:draw()
	personai.super.draw(self)
	self.info = CCNode:create()
	self.info:setScale(0.6)
	self:addChild(self.info)
	self:initInfo();
end

function personai:updateEntity(dt)
	self.tree:tick(self,self.blackboard)
	personai.super.updateEntity(self,dt)
end

function personai:setEnemys(enemys)
	self.enemys = enemys;
end

function personai:hurtByTarget(hurt)
	self.curHp = self.curHp - hurt
	self:changeInfo();
	if self.curHp < 0 then
		self:dead();
	end
end

function personai:bigFire()
	personai.super.bigFire(self)
	local container = self.group.parent.center_node;
	local jsonFile = "zhishengji_jineng.json"
	local atlasFile = "zhishengji_jineng.atlas"
	self.btt = sp.SkeletonData:create(jsonFile,atlasFile)
	self.firetemp = sp.SkeletonAnimation:create(self.btt)
	self.firetemp:setAnchorPoint(cc.p(0.5,0.5))
	container:addChild(self.firetemp)

	self.firetemp:setAnimation(0, "animation1", false)
	self.firetemp:registerSpineEventHandler(handler(self,function (self,event)
		for i = 1, #self.enemys, 1 do
			local en = self.enemys[i];
			if self:fireSigh(en) and en.isDeaded == false then
				pos = en:hurtByTarget(100)
			end
		end
		-- container:removeAllChildren(true)
    end), sp.EventType.ANIMATION_COMPLETE)

	local pos = nil;
    for i = 1, #self.enemys, 1 do
		local en = self.enemys[i];
		if self:fireSigh(en) and en.isDeaded == false then
			pos = en:getPosition()
		end
	end

	self.firetemp:setPosition(pos)
end

--人物个人和血量信息
function personai:initInfo()
	-- self.bar = GameUtil:createProgressBar({"public_pg_ziyuantiao_di.png", "public_pg_ziyuantiao.png"}, cc.p(0.5, 0.5))
	-- self.bar:setPositionY(130)
	-- self.info:addChild(self.bar)
	-- self:changeInfo();
end

function personai:changeInfo()
	-- self.bar:setValue(self.curHp/self.maxHp*100)
end

return personai