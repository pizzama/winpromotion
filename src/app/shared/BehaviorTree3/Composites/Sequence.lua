
local Sequence = class("Sequence",b3.Composite)

function Sequence:onTick(tick)
	for i=1,#self.children do
		local status = self.children[i]:execute(tick)
		if status ~= b3.Com.SUCCESS then
			return status
		end
	end
	return b3.Com.SUCCESS
end

return Sequence