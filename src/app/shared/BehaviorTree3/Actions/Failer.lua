
local Failer = class("Failer",b3.Action)

function Failer:onTick(tick)
	return b3.Com.FAILURE
end

return Failer