
local Repeater = class("Repeater",b3.Decorator)

function Repeater:onCreate(properties)
	assert(properties.maxLoop,"maxLoop parameter in maxLoop decorator is an obligatory parameter")
	self.maxLoop = properties.maxLoop or -1
end

function Repeater:onOpen(tick)
	tick.blackboard:set("i",0,tick.tree.id,self.id)
end

function Repeater:onTick(tick)
	if not self.child then
		return b3.Com.ERROR
	end

	local i = tick.blackboard:get("i",tick.tree.id,self.id)
	local status = b3.Com.SUCCESS

	while self.maxLoop < 0 or i < self.maxLoop do
		status = self.child:execute(tick)
		if status == b3.Com.SUCCESS or status == b3.Com.FAILURE then
			i = i + 1
		else
			break
		end
	end

	tick.blackboard:set("i",i,tick.tree.id,self.id)
	return status
end

return Repeater