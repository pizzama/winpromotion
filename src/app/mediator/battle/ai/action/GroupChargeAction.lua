local GroupChargeAction = class("GroupChargeAction", b3.Action)
local vector2d = require("app.shared.vector2d");

function GroupChargeAction:tick(tick)
	local group = tick.target
	for i = 1, #group.entityArray, 1 do
		local en = group.entityArray[i];
		if en.isDeaded == false then
			en:setEnemys(group.curEnemyGroup.entityArray)
			en.maxspeed = 2
			en:charge();
			en:arrive(vector2d.new(group.targetx,group.targety))
			en:flock(group.entityArray);
			en:updateEntity()
		end
	end
	return b3.Com.SUCCESS
end


return GroupChargeAction