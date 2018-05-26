local IsBigFireCondition = class("IsBigFireCondition", b3.Condition)


function IsBigFireCondition:tick(tick)
	local my = tick.target
	if my.leader == false then
		return b3.Com.FAILURE
	end
	local time = tick.blackboard:get("fire",tick.tree.id,self.id)
	if time == nil then
		time = os.time()
		tick.blackboard:set("fire",time ,tick.tree.id,self.id)
	end
	local curtime = os.time();
	if curtime - time > 5 then
		tick.blackboard:set("fire",curtime ,tick.tree.id,self.id)

		return b3.Com.SUCCESS
	end

	return b3.Com.FAILURE
end

return IsBigFireCondition