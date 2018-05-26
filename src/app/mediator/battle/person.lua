local person = class("person", __G_REQUIRE("app.ui.battle.steeredEntity"))
local vector2d = __G_REQUIRE("app.shared.vector2d");
--定义人物持有武器
local weapon = {"Handgun","Rifle","Slash"}
local sightDist = {Handgun=300,Slash=70,Rifle=250}
function person:ctor(feature,totalscale)
	print("get feature:" .. tostring(feature) .. ";" .. tostring(totalscale))
	self.feature1 = feature
	self.feature2 = math.random(1,3)
	self.totalscale = totalscale or 1;
	self.fireSighDist = 200 --攻击范围，
	self.isDeaded = false;
	person.super.ctor(self)
end

function person:draw()
	local jsonFile = "person01.json"
	local atlasFile = "person01.atlas"
	self.skeletonData = sp.SkeletonData:create(jsonFile,atlasFile)
	self.spk = sp.SkeletonAnimation:create(self.skeletonData)
	self.spk:setAnchorPoint(cc.p(0.5,0.5))
	self.spk:setScale(self.totalscale)
	self:addChild(self.spk)
	self.spk:setAnimation(0, "idle3", true)
	self.state = "walk"
	self.prestate = "walk"
	self.curDirection = nil
	self.curScalex = nil
	self.holdweapon=weapon[math.random(1,3)]
	self.fireSighDist = sightDist[self.holdweapon];
	self.enemy = nil;--攻击目标
	self.deadDes = "Death_putong0" --死亡方式

	self.spk:registerSpineEventHandler(handler(self,function (self,event)
		local a,b=string.find(event.animation,self.prestate) --预设状态
		if a == nil and b == nil then
			--改变状态
			print("the current state:" .. tostring(self.prestate))
			if self.prestate == "attack" then
				self.spk:setAnimation(0, self.holdweapon .. "_attack0" .. self.curDirection, true)
				self.spk:setToSetupPose();
			end
			
			if self.prestate == "walk" then
				if self.curDirection ~= nil then
					self.spk:setAnimation(0, "walk" .. self.curDirection, true)
					self.spk:setScaleX(self.curScalex*self.totalscale);
					self.spk:setToSetupPose();
					self.enemy = nil;
				end
			end

			if self.prestate == "Enter" then
				if self.curDirection ~= nil then
					self.spk:setAnimation(0, "walk" .. self.curDirection, true)
					self.spk:setScaleX(self.curScalex*self.totalscale);
					self.spk:setToSetupPose();
					self.enemy = nil;
				end
			end

			if self.prestate == "idle" then
				self.spk:setAnimation(0, "idle" .. self.curDirection, true)
				self.spk:setToSetupPose();
			end

			if self.prestate == "Buff" then
				-- self.spk:setAnimation(0, "Buff", true)
				-- self.spk:setToSetupPose();
			end

			self:changeState()
		end
    end), sp.EventType.ANIMATION_COMPLETE)

    self.spk:registerSpineEventHandler(handler(self,function (self,event)
        local eventData = event.eventData
        local name = eventData.name
        if name == "fire" then 
        	self.enemy:hurtByTarget(100);
        elseif name == "deadevent" then
			self.spk:setAnimation(0, self.holdweapon .. "_"  ..self.deadDes .. "tingzhi", true)
        end
    end), sp.EventType.ANIMATION_EVENT)
end

function person:fire()
	if self.isDeaded then
		return;
	end

	if self.prestate == "attack" then
		return;
	else
		self.prestate = "attack"
	end
end

function person:bigFire()
	if self.isDeaded then
		return;
	end
	print("person:: buff")
	self.prestate = "Buff"
	self.spk:setAnimation(0, "Buff", true)
	self.spk:setToSetupPose();
end

function person:setEnemy(entity)
	self.enemy = entity;
end

function person:walk()
	if self.isDeaded then
		return 
	end
	self.prestate = "walk"
end

function person:charge()
	if self.isDeaded then
		return 
	end
	self.prestate = "Enter"
end

function person:idle()
	if self.isDeaded then
		return 
	end
	print("start to idle")
	self.prestate = "idle"
end

function person:dead()
	self.isDeaded = true
	self.prestate = "dead"
	self:changeState();
	self.deadDes = "Death_putong0" .. math.random(1,2) --动态产生死亡方式
	self.spk:setAnimation(0, self.holdweapon .. "_" .. self.deadDes, true)
	self.spk:setToSetupPose();
end

function person:changeState()
	self.state = self.prestate;
end

function person:flock(entitys)
	if(self.state == "walk") then
		person.super.flock(self,entitys)
	end
end

function person:updateEntity(dt)
	--人物在行走和冲锋过程中是否产生位移
	if(self.state == "walk" or self.state == "Enter") then
		self.steeringforce:truncate(self.maxforce);
		self.steeringforce = self.steeringforce / self.mass;
		self.velocity = self.velocity + self.steeringforce;
		self.steeringforce = vector2d.new();
		self.velocity:truncate(self.maxspeed);
		self.posv2d = self.posv2d + self.velocity;
		if (self.edgebehavior == "wrap") then
			self:wrap();
		elseif(self.edgebehavior == "bounce") then
			self:bounce();
		end
		self:setPosition(self.posv2d.x,self.posv2d.y)
		local angle = tonumber(string.format("%.2f", self.velocity:getAngle()));
		local dic,scale = self:getPersonAngle(angle);
		if self.curDirection ~= dic or self.curScalex ~= scale then
			self.curDirection = dic;
			self.curScalex = scale;
			self.spk:setAnimation(0, "walk" .. self.curDirection, true)
			self.spk:setScaleX(self.curScalex*self.totalscale);
			self.spk:setToSetupPose();
		end
	end

end

function person:fireSigh(entity)
	if self.posv2d:dist(entity.posv2d) > self.fireSighDist then
		return false
	end

	local heading = self.velocity:clone():normalize();
	local difference = entity.posv2d - self.posv2d;
	local dotProd = difference:dotProd(heading);
	if(dotProd < 0) then 
		return false;
	else
		return true;
	end;
end

--根据角度获得角色的朝向信息
function person:getPersonAngle(angle)
	local dic = nil;
	local scalex = nil;
	if angle == 0 then
		dic = 3;
		scalex = -1;
	elseif angle > 0 and angle < 1.57 then
		dic = 2;
		scalex = 1;
	elseif angle > 1.57 and angle < 3.14 then
		dic = 2;
		scalex = -1;
	elseif angle == 3.14 or angle == -3.14 then
		dic = 3;
		scalex = 1;
	elseif angle == 1.57 then
		dic = 1
		scalex = 1;
	elseif angle == -1.57 then
		dic = 5
		scalex = 1
	elseif angle < -1.57 and angle > -3.14 then
		dic = 4;
		scalex = 1
	elseif angle > -1.57 and angle < 0 then
		dic = 4;
		scalex = -1
	end
	return dic,scalex
end

--2.5d景深排序
function person:depth()
	local p3d = screenToIso(self.posv2d.x,self.posv2d.y)
	local depth = (p3d.x + p3d.z)*0.866 - p3d.y*0.707
	return depth
end

return person