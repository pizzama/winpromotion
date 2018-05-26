
local Error = class("Error",b3.Action)

function Error:onTick(tick)
	return b3.Com.ERROR
end

return Error