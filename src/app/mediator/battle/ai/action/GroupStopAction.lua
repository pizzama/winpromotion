local GroupStopAction = class("GroupStopAction", b3.Action)
local vector2d = require("app.shared.vector2d");


function GroupStopAction:tick(tick)
	return b3.Com.SUCCESS
end


return GroupStopAction