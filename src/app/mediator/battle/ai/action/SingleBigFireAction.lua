local SingleBigFireAction = class("SingleBigFireAction", b3.Action)

function SingleBigFireAction:tick(tick)
	local my = tick.target
	my:bigFire();
	return b3.Com.SUCCESS
end


return SingleBigFireAction