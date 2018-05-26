
local Decorator = class("Decorator",b3.BaseNode)

function Decorator:ctor(nodeData)
	Decorator.super.ctor(self,nodeData)
	self.category = b3.Com.DECORATOR
	self.child = nodeData and nodeData.child or nil --存放唯一子节点
end

return Decorator