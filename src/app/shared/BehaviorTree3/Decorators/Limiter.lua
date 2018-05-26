
local Limiter = class("Limiter",b3.Decorator)

function Limiter:onCreate(properties)
	assert(properties.maxLoop,"maxLoop parameter in Limiter decorator is an obligatory parameter")
	self.maxLoop = properties.maxLoop
end

function Limiter:onOpen(tick)
	tick.blackboard:set("i",0,tick.tree.id,self.id)
end

function Limiter:onTick(tick)
	if not self.child then
		return b3.Com.ERROR
	end

	local i = tick.blackboard:get("i",tick.tree.id,self.id)

	if i < self.maxLoop then
		local status = self.child:execute(tick)

		if status == b3.Com.SUCCESS or status == b3.Com.FAILURE then
			tick.blackboard:set("i",i+1,tick.tree.id,self.id)
		end
		return status
	end
	return b3.Com.FAILURE
end

return Limiter