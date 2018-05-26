local view_base = class( "viewBase",nil );

view_base.m_control = nil;
view_base.m_type = 1
view_base.m_rootView = nil;
view_base.m_maskView = nil;

--[[
	此方法重载后用来做view的创建
]]
function view_base:createView(  )
	-- body
	return nil;
end
--[[
	使用方法，与参数性质同controlBase
]]
function view_base:updateMsg( msg , data , flag , alias)
	-- body
	self.m_control:updateMsg( msg,data,flag,alias );
end

--[[
	此方法是用来给自己view发命令用的
]]
function view_base:updateCommand( command , data )
	-- body
	self:onCommand(command,data);
end

function view_base:destroy(  )
	-- body
end

function view_base:getType(  )
	-- body
	return self.m_type;
end

function view_base:getRootView(  )
	-- body
	return self.m_rootView;
end


-- ======================= a stupid cut of line ===============================

--[[
	此方法是重载后用来接受消息的
]]
function view_base:onCommand( command , data )
	-- body
end

--[[
	页面调用create时调用
]]
function view_base:onCreate(  )
	-- body
	cclog("-------------- view onCreate " .. self.m_control.m_data:getName());
end

--[[
	页面进入后
]]
function view_base:onEnter(  )
	-- body
	cclog("-------------- view onEnter " .. self.m_control.m_data:getName());
end

--[[
	锁定所有的点击事件
]]
function view_base:lockTouch(  )
	-- body
	if(self.m_rootView ~= nil)then
		if(self.m_maskView ~= nil)then
			return;
		end
		local function onTouch( eventType, x, y )
			-- body
			if(eventType == "began" )then
				return true;
			end
		end
		self.m_maskView = CCLayer:create();
		self.m_maskView:registerScriptTouchHandler(onTouch,false, GLOBAL_TOUCH_PRIORITY ,true);
		self.m_maskView:setTouchEnabled(true);
		self.m_rootView:addChild(self.m_maskView);
	end
end

--[[
	解锁所有的点击事件
]]
function view_base:unlockTouch(  )
	-- body
	if(self.m_maskView == nil)then
		return;
	else
		self.m_maskView:removeAllChildren(true);
		self.m_maskView = nil;
	end
end


return view_base;