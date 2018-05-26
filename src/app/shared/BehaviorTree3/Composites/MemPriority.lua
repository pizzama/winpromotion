
local MemPriority = class("MemPriority",b3.Composite)

function MemPriority:onOpen(tick)
	tick.blackboard:set("runningChild",1,tick.tree.id,self.id)
end

function MemPriority:onTick(tick)
	local child = tick.blackboard:get("runningChild",tick.tree.id,self.id)
	for i=child,#self.children do
		local status = self.children[i]:execute(tick)
		if status ~= b3.Com.FAILURE then
			if status == b3.Com.RUNNING then
				tick.blackboard:set("runningChild",i,tick.tree.id,self.id)
			end
			return status
		end
	end
	return b3.Com.FAILURE
end

return MemPriority