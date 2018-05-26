
local Composite = class("Composite",b3.BaseNode)

function Composite:ctor(nodeData)
	Composite.super.ctor(self,nodeData)
	self.category = b3.Com.COMPOSITE
	self.children = nodeData and nodeData.children or {} --存放子节点
end

return Composite