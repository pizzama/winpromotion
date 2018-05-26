
local Succeeder = class("Succeeder",b3.Action)

function Succeeder:onTick(tick)
	return b3.Com.SUCCESS
end

return Succeeder