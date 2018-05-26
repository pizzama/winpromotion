
local Condition = class("Condition",b3.BaseNode)

function Condition:ctor(nodeData)
	Condition.super.ctor(self,nodeData)
	self.category = b3.Com.CONDITION
end

function Condition:onTick(tick)
	return b3.Com.SUCCESS
end

return Condition