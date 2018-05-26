ENTITYEDGEBEHAVIOR = {}
ENTITYEDGEBEHAVIOR.BOUNCE = "edgebehavior_bounce"
ENTITYEDGEBEHAVIOR.WRAP = "edgebehavior_wrap"
ENTITYEDGEBEHAVIOR.NONE = "edgebehavior_none"

local entity = class("entity", function ()
	return CCNode:create()
end)

function entity:ctor()
	self.mass = 1;
	self.maxspeed = 2;
	self.velocity = cc.p(0,0)
	self.nodeDirection = 0;--图片或者动画的方向,默认方向是朝右 使用弧度0,math.pi/2,math.pi,1.5*math.pi
	self.stagewidth = 0;
	self.stageheight = 0;
	self.edgebehavior = ENTITYEDGEBEHAVIOR.BOUNCE
end

function entity:moveSpeed(value)
	self.velocity = cc.pSetLength(self.velocity,5);
end

function entity:moveMaxSpeed(value)
	self.maxspeed = value;
end

function entity:moveAngle(value) --value 使用弧度
	self.velocity = cc.pSetAngle(self.velocity,value);
end

--素材默认方向 --使用弧度
function entity:setNodeDirection(angle)
	self.nodeDirection = angle;
end

function entity:setStageBounds(width,height)
	self.stagewidth = width;
	self.stageheight = height;
end

function entity:edgebehavior(value)
	self.edgebehavior = value;
end

function entity:updatePosition(dt)
	self.velocity = cc.pTruncate(self.velocity,self.maxspeed)
	local ps = self:getPosition();
	ps = cc.pAdd(ps,self.velocity);
	if (self.edgebehavior == ENTITYEDGEBEHAVIOR.WRAP) then
		ps = self:wrap(ps);
	elseif(self.edgebehavior == ENTITYEDGEBEHAVIOR.BOUNCE) then
		ps = self:bounce(ps);
	end
	self:setPosition(ps)
end

function entity:updateAngle(dt)
	local angle = math.deg(self.nodeDirection-cc.pToAngleSelf(self.velocity));
	self:setRotation(angle);
end

function entity:updateEntity(dt)
	--更新分成两部分，方便iso模型更新方向的单独处理
	self:updatePosition(dt);
	self:updateAngle(dt);
end

--检测当前位置是否超出边界
function entity:bounce(ps)
	if(ps.x > self.stagewidth) then
		ps.x = self.stagewidth;
		self.velocity.x = self.velocity.x * -1
	elseif(ps.x < 0) then
		ps.x = 0;
		self.velocity.x = self.velocity.x * -1
	end

	if(ps.y > self.stageheight) then
		ps.y = self.stageheight;
		self.velocity.y = self.velocity.y * -1
	elseif (ps.y < 0) then
		ps.y = 0;
		self.velocity.y = self.velocity.y * -1
	end
	return ps;
end

function entity:wrap(ps)
	local ps = self:getPosition();
	if(ps.x > self.stagewidth) then ps.x = 0; end
	if(ps.x < 0) then ps.x = self.stagewidth; end
	if(ps.y > self.stageheight) then ps.y = 0; end
	if(ps.y < 0) then ps.y = self.stageheight; end
	return ps;
end

return entity