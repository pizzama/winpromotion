local InFireSighCondition = class("InFireSighCondition", b3.Condition)

function InFireSighCondition:tick(tick)
	local my = tick.target
	for i = 1, #my.enemys, 1 do
		local en = my.enemys[i];
		if my:fireSigh(en) and en.isDeaded == false then
			my:setEnemy(en)
			return b3.Com.SUCCESS
		end
	end
	return b3.Com.FAILURE
end


return InFireSighCondition