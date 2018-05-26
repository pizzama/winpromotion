
b3         				= {}
b3.Com 					= require('app.shared.BehaviorTree3.Com')
		
--core		
b3.BaseNode 			= require('app.shared.BehaviorTree3.Core.BaseNode')
b3.Action 				= require('app.shared.BehaviorTree3.Core.Action')
b3.Decorator 			= require('app.shared.BehaviorTree3.Core.Decorator')
b3.Condition 			= require('app.shared.BehaviorTree3.Core.Condition')
b3.Composite 			= require('app.shared.BehaviorTree3.Core.Composite')
b3.BehaviorTree 		= require('app.shared.BehaviorTree3.Core.BehaviorTree')
b3.Blackborad 			= require('app.shared.BehaviorTree3.Core.Blackborad')
b3.Tick 				= require('app.shared.BehaviorTree3.Core.Tick')
		
--Action		
b3.Error 				= require('app.shared.BehaviorTree3.Actions.Error')
b3.Failer 				= require('app.shared.BehaviorTree3.Actions.Failer')
b3.Runner 				= require('app.shared.BehaviorTree3.Actions.Runner')
b3.Succeeder 			= require('app.shared.BehaviorTree3.Actions.Succeeder')
b3.Wait 				= require('app.shared.BehaviorTree3.Actions.Wait')
		
--Composites		
b3.Sequence 			= require('app.shared.BehaviorTree3.Composites.Sequence')
b3.Priority 			= require('app.shared.BehaviorTree3.Composites.Priority')
b3.MemSequence 			= require('app.shared.BehaviorTree3.Composites.MemSequence')
b3.MemPriority  		= require('app.shared.BehaviorTree3.Composites.MemPriority')
b3.IfelseSelector  		= require('app.shared.BehaviorTree3.Composites.IfelseSelector')
b3.WeightSelector 		= require('app.shared.BehaviorTree3.Composites.WeightSelector')
		
--Decorators		
b3.Inverter 			= require('app.shared.BehaviorTree3.Decorators.Inverter')
b3.Limiter 				= require('app.shared.BehaviorTree3.Decorators.Limiter')
b3.MaxTime 				= require('app.shared.BehaviorTree3.Decorators.MaxTime')
b3.Repeater 			= require('app.shared.BehaviorTree3.Decorators.Repeater')
b3.RepeatUntilFailure 	= require('app.shared.BehaviorTree3.Decorators.RepeatUntilFailure')
b3.RepeatUntilSuccess 	= require('app.shared.BehaviorTree3.Decorators.RepeatUntilSuccess')
