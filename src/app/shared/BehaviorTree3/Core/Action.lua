
local Action = class("Action",b3.BaseNode)

function Action:ctor(nodeData)
	Action.super.ctor(self,nodeData)
	self.category = b3.Com.ACTION
end

return Action