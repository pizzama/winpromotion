local IsDeadCondition = class("IsDeadCondition", b3.Condition)

function IsDeadCondition:tick(tick)
	local my = tick.target
	if my.isDeaded then
		return b3.Com.FAILURE
	else
		return b3.Com.SUCCESS
	end
	
end


return IsDeadCondition