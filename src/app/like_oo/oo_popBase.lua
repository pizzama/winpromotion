-- if you want create a pop window,you mast inheritance the oo_viewBase
local pop_base = class( "popBase" , require("like_oo.oo_viewBase") );
pop_base.m_type = 2;
pop_base.m_selfClose = false;
pop_base.m_priority = 0;
pop_base.m_normal = true;


function pop_base:createView(  )
	-- body
	self.m_rootView = cc.Layer:create();
	local function onTouch( eventType, x, y )
		-- body
		-- cclog("------pop_base------- eventType " .. eventType .. " name:" .. self.m_control.m_model:getName());
		if eventType == "began" then
            return true;    --intercept event
        elseif(eventType == "ended")then
        	if(self.m_selfClose)then
        		self.m_control:closeView();
        	end
        end
	end
	local priporty = 1;
	if(not self.m_normal)then
		priporty = -100;
	end
	self.m_rootView:registerScriptTouchHandler(onTouch , false , priporty , true);
	self.m_rootView:setTouchEnabled(true);
	self:onCreate();
	self:action_option();
	return self.m_rootView;
end

function pop_base:canClose( can )
	-- body
	self.m_selfClose = can;
end

function pop_base:consumeTouch( con )
	-- body
	self.m_rootView:setTouchEnabled(con);
end

-- 设置优先级
function pop_base:setPriority( priority )
	-- body
	-- self.m_rootView:setZOrder(priority);
	self.m_priority = priority;
	local parentView = self.m_rootView:getParent();
	if(parentView ~= nil)then
		parentView:reorderChild(m_rootView , priority);
	end
end
-- 得到当前优先级别
function pop_base:getPriority(  )
	-- body
	return self.m_priority;
end


function pop_base:destroy(  )
	-- body
	cclog("-------- destroy view " .. self.m_control.m_data:getName());
	-- if game_scene:getCurrentUiName() ~= "game_main_scene" then
	-- 	self.m_rootView:removeFromParentAndCleanup(true);
	-- end
	self:consumeTouch(false);
	self.m_rootView:removeFromParentAndCleanup(true);

end

-- 动画效果
function pop_base:action_option()
	--增加pop框的弹出效果
	if self.m_control.m_model.transfer == "fade" then
		self.m_rootView:setCascadeOpacityEnabled(true)
		self.m_rootView:setOpacity(0)
		local fadeIn = cc.FadeIn:create(1)
		self.m_rootView:runAction(fadeIn);
	elseif self.m_control.m_model.transfer == "scale" then
		self.m_rootView:setScale(0.1)
		local scaleto = cc.ScaleTo:create(0.2, 1.2)
		local scaleby = cc.ScaleTo:create(0.12, 1)
		self.m_rootView:runAction(cc.Sequence:create(scaleto, scaleby))
	end
end




return pop_base;