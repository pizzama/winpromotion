local battleModel = class("battleModel",__G_REQUIRE("app.like_oo.oo_dataBase"));
__G_REQUIRE("app.shared.BehaviorTree3.b3")

--add action
b3.GroupMoveAction = __G_REQUIRE("app.ui.battle.ai.action.GroupMoveAction")
b3.GroupChargeAction = __G_REQUIRE("app.ui.battle.ai.action.GroupChargeAction")
b3.GroupStopAction = __G_REQUIRE("app.ui.battle.ai.action.GroupStopAction")
b3.SingleFireAction = __G_REQUIRE("app.ui.battle.ai.action.SingleFireAction")
b3.SearchEnemyAction = __G_REQUIRE("app.ui.battle.ai.action.SearchEnemyAction")
b3.SingleBigFireAction = __G_REQUIRE("app.ui.battle.ai.action.SingleBigFireAction")

--add condtion
b3.InGroupSignCondition = __G_REQUIRE("app.ui.battle.ai.condition.InGroupSignCondition")
b3.InFireSighCondition = __G_REQUIRE("app.ui.battle.ai.condition.InFireSighCondition")
b3.IsDeadCondition = __G_REQUIRE("app.ui.battle.ai.condition.IsDeadCondition")
b3.IsGroupDeadCondition = __G_REQUIRE("app.ui.battle.ai.condition.IsGroupDeadCondition")
b3.IsBigFireCondition = __G_REQUIRE("app.ui.battle.ai.condition.IsBigFireCondition")
function battleModel:onCreate()
	-- body
	self:getData()
end

function battleModel:onEnter()

end

return battleModel;