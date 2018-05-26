
local Runner = class("Runner",b3.Action)

function Runner:onTick(tick)
	return b3.Com.RUNNING
end

return Runner