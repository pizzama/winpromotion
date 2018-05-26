local IsGroupDeadCondition = class("IsGroupDeadCondition", b3.Condition)

function IsGroupDeadCondition:tick(tick)
	local group = tick.target
	if group:isAllDead() then
		return b3.Com.FAILURE
	else
		return b3.Com.SUCCESS
	end
end


return IsGroupDeadCondition