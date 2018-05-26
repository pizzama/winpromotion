local SingleFireAction = class("SingleFireAction", b3.Action)

function SingleFireAction:tick(tick)
	local my = tick.target
	my:fire();
	return b3.Com.SUCCESS
end


return SingleFireAction