local IsGroupDeadCondition = class("IsGroupDeadCondition", b3.Condition)

function IsGroupDeadCondition:tick(tick)
	local group = tick.target
	if group:enemyIsInGroupSigh() then
		return b3.Com.SUCCESS
	else
		return b3.Com.FAILURE
	end
end


return IsGroupDeadCondition