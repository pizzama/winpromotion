local vector2d = class("vector2d",{})

function vector2d:ctor(x,y)
	if x then
		self.x = x;
	else 
		self.x = 0;
	end

	if y then
		self.y = y;
	else
		self.y = 0;
	end
	self:override()
end

function vector2d:override()
	vector2d.__add = vector2d.add
	vector2d.__sub = vector2d.subtract
	vector2d.__mul = vector2d.multiply
	vector2d.__div = vector2d.divide
	vector2d.__tostring = vector2d.tostring
end

function vector2d:setLength(value)
	local a = self:getAngle()
	self.x = math.cos(a)*value
	self.y = math.sin(a)*value
end

function vector2d:getLength()
	return math.sqrt(self:getLengthSQ())
end

function vector2d:getLengthSQ()
	return self.x * self.x + self.y * self.y
end

function vector2d:setAngle(value)
	local l = self:getLength();
	self.x = math.cos(value)*l;
	self.y = math.sin(value)*l;
end

function vector2d:getAngle()
	return math.atan2(self.y,self.x)
end

function vector2d:normalize()
	local l = self:getLength();
	if(l == 0) then
		self.x = 1;
		return self;
	end

	self.x = self.x / l;
	self.y = self.y / l;
	return self; 
end

function vector2d:isNormalized()
	local l = self:getLength();
	return l == 1;
end

function vector2d:truncate(max)
	local l = self:getLength();
	local rs = math.min(max,l)
	self:setLength(rs);
	return self;
end

function vector2d:reverse()
	self.x = -self.x;
	self.y = -self.y;
	return self;
end

function vector2d:zero()
	self.x = 0;
	self.y = 0;
	return self;
end

function isZero()
	return self.x == 0 and self.y == 0
end

function vector2d:clone()
	local vc = vector2d.new(self.x,self.y);
	return vc
end

function vector2d:dotProd(v2)
	return self.x*v2:getX() + self.y*v2:getY();
end

function vector2d:crossProd(v2)
	return self.x*v2:getY() - self.y*v2:getX();
end

function vector2d:angleBetween(v1,v2)
	if(not v1:isNormalized()) then
		v1 = v1:clone():normalize();
	end
	if(not v2:isNormalized()) then
		v2 = v2:clone():normalize();
	end
	return math.acos(v1:dotProd(v2));
end

function vector2d:getPerp()
	return vector2d.new(-self.y,self.x);
end

function vector2d:sign(v2)
	local prep = self:getPerp();
	return prep:dotProd(v2) < 0 and -1 or 1
end

function vector2d:distSQ(v2)
	local dx = v2:getX() - self.x;
	local dy = v2:getY() - self.y;
	return dx * dx + dy * dy
end

function vector2d:dist(v2)
	return math.sqrt(self:distSQ(v2))
end

function vector2d:add(v2)
	return vector2d.new(self.x + v2:getX(), self.y + v2:getY());
end

function vector2d:subtract(v2)
	return vector2d.new(self.x - v2:getX(), self.y - v2:getY());
end

function vector2d:multiply(value)
	return vector2d.new(self.x * value, self.y * value);
end

function vector2d:divide(value)
	return vector2d.new(self.x / value, self.y / value);
end

function vector2d:equals(v2)
	return self.x == v2:getX() and self.y == v2:getY()
end

function vector2d:getX()
	if not self.x then
		self.x = 0;
	end
	return self.x;
end

function vector2d:setX(value)
	self.x = value;
end

function vector2d:getY()
	if not self.y then
		self.y = 0;
	end
	return self.y;
end

function vector2d:setY(value)
	self.y = value;
end

function vector2d:tostring()
	return "[vector2d(x:" .. self.x ..",y:" .. self.y .. ")]"
end


return vector2d;