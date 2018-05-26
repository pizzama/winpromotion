local steeredEntity = class("steeredEntity", __G_REQUIRE("app.ui.battle.entity"))

local vector2d = __G_REQUIRE("app.shared.vector2d");

function steeredEntity:ctor()
	self.maxforce = 1;
	self.wangderDistance = 20;--移动位置
	self.wanderRadius = 2;--移动半径
	self.wanderAngle = 0;--移动角度
	self.wanderRange = 1;
	self.arrivalThreshold = 100;
	self.inSightDist = 500;--搜寻视野范围
	self.tooCloseDist = 60;--距离范围
	self.steeringforce = cc.p(0,0)
	steeredEntity.super.ctor(self)
end

function steeredEntity:updateEntity(dt)
	self.steeringforce = cc.pTruncate(self.steeringforce,self.maxforce)
	self.steeringforce = cc.pDivide(self.steeringforce,self.mass)
	self.velocity = cc.pAdd(self.velocity,self.steeringforce)
	self.steeringforce = cc.p(0,0)
	steeredEntity.super.updateEntity(self,dt);
end

function steeredEntity:wander()
	local center = cc.pMul(cc.pNormalize(cc.pClone(self.velocity)),self.wangderDistance)
	local offset = cc.p(0,0)
	offset = cc.pSetLength(offset,self.wanderRadius);
	offset = cc.pSetAngle(offset,self.wanderAngle);
	self.wanderAngle = self.wanderAngle + math.random()*self.wanderRange - self.wanderRange*0.5;
	local force = cc.pAdd(center,offset);
	self.steeringforce = cc.pAdd(self.steeringforce,force);
end

function steeredEntity:seek(v2)
	local pos = self:getPosition();
	local desiredVelocity = cc.pSub(v2,pos);
	desiredVelocity = cc.pNormalize(desiredVelocity);
	desiredVelocity = cc.pMul(desiredVelocity,self.maxspeed);
	local force = cc.pSub(desiredVelocity,self.velocity);
	self.steeringforce = cc.pAdd(self.steeringforce,force);
end

function steeredEntity:flee(v2)
	local pos = self:getPosition();
	local desiredVelocity = cc.pSub(v2,pos);
	desiredVelocity = cc.pNormalize(desiredVelocity);
	desiredVelocity = cc.pMul(desiredVelocity,self.maxspeed);
	local force = cc.pSub(desiredVelocity,self.velocity);
	self.steeringforce = cc.pSub(self.steeringforce,force);
end

function steeredEntity:arrive(v2)
	local pos = self:getPosition();
	local desiredVelocity = cc.pSub(v2,pos);
	desiredVelocity = cc.pNormalize(desiredVelocity);

	local dist = cc.pDistanceSQ(pos,v2);
	if(dist > self.arrivalThreshold) then
		desiredVelocity = cc.pMul(desiredVelocity,self.maxspeed);
	else
		desiredVelocity = cc.pMul(desiredVelocity,(self.maxspeed*dist/self.arrivalThreshold))
	end
	local force = cc.pSub(desiredVelocity,self.velocity);
	self.steeringforce = cc.pAdd(self.steeringforce,force);
end

function steeredEntity:pursue(entity)
	local pos = self:getPosition();
	local aheadtime = cc.pDistanceSQ(pos,entity:getPosition())/self.maxspeed;
	local predicted = cc.pAdd(entity:getPosition(),cc.pMul(entity.velocity,aheadtime))
	self:seek(predicted);
end

function steeredEntity:evade(entity)
	local pos = self:getPosition();
	local aheadtime = cc.pDistanceSQ(pos,entity:getPosition())/self.maxspeed;
	local predicted = cc.pSub(entity:getPosition(),cc.pMul(entity.velocity,aheadtime))
	self:flee(predicted)
end

function steeredEntity:flock(entitys)
	local averageVelocity = cc.pClone(self.velocity);
	local averagePostion = cc.p(0,0)
	local inSightCount = 0;
	for i = 1, #entitys, 1 do
		local en = entitys[i];
		if(tostring(en) ~= tostring(self) and self:inSight(en)) then
			averageVelocity = cc.pAdd(averageVelocity,en.velocity);
			averagePostion = cc.pAdd(averagePostion,en:getPosition());
			if(self:tooClose(en)) then
				self:flee(en:getPosition())
			end
			inSightCount = inSightCount + 1;
		end
	end

	if(inSightCount > 0) then
		averageVelocity = cc.pDivide(averageVelocity,inSightCount);
		averagePostion = cc.pDivide(averagePostion,inSightCount);
		self:seek(averagePostion);
		self.steeringforce = cc.pAdd(self.steeringforce,cc.pSub(averageVelocity,self.velocity))
	end
end

function steeredEntity:inSight(entity)
	if cc.pDistanceSQ(self:getPosition(),entity:getPosition()) > self.inSightDist then
		return false
	end

	local heading = cc.pNormalize(cc.pClone(self.velocity));
	local difference = cc.pSub(entity:getPosition(),self:getPosition());
	local dotProd = cc.pDot(difference,heading);
	if(dotProd < 0) then 
		return false;
	else
		return true;
	end;
end

function steeredEntity:tooClose(entity)
	local dist = cc.pDistanceSQ(self:getPosition(),entity:getPosition())
	return dist < self.tooCloseDist
end

return steeredEntity