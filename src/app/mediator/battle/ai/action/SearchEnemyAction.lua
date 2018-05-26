local SearchEnemyAction = class("SearchEnemyAction", b3.Action)
local vector2d = require("app.shared.vector2d");

function SearchEnemyAction:tick(tick)
	local group = tick.target;
	local enemys = group.enemys;
	if enemys and #enemys > 0 then
		for i = 1, #enemys, 1 do
			local gp = enemys[i];
			if gp:isAllDead() == false then
				group.curEnemyGroup = gp;
				return b3.Com.SUCCESS			
			end
		end
	end
	group.curEnemyGroup = nil
	group:idle();
	return b3.Com.FAILURE
end


return SearchEnemyAction