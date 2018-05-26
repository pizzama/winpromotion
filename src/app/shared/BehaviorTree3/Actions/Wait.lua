
local Wait = class("Wait",b3.Action)

function Wait:onCreate(properties)
	self.endTime = properties.milliseconds or 0
	print("self.endTime:" .. tostring(self.endTime))
end

function Wait:onOpen(tick)
	local startTime = os.time()
	tick.blackboard:set("startTime",startTime, tick.tree.id, self.id)
end

function Wait:onTick(tick)
	local currTime = os.time()
	local startTime = tick.blackboard:get("startTime",tick.tree.id,self.id)
	print("wait tick:" .. tostring(currTime - startTime))
	if currTime - startTime > self.endTime then
		return b3.Com.SUCCESS
	end
	return b3.Com.RUNNING
end

return Wait