--条件执行节点
--条件执行节点必须要有3个子节点，第一个子节点是条件分支，第二个子节点是“真时执行”分支，
--第三个子节点是“假时执行”分支。如果条件为真，那么执行“真时执行”分支；否则，执行“假时执行”分支。

local IfelseSelector = class("IfelseSelector",b3.Composite)

function IfelseSelector:onTick(tick)
	if #self.children ~= 3 then
		error("IfelseSelector's children num is not satisfiable, is only three node")
	end

	local status = self.children[1]:execute(tick);
	if status == b3.Com.SUCCESS then
		status = self.children[2]:execute(tick);
	else
		status = self.children[3]:execute(tick);
	end

	return status
end

return IfelseSelector