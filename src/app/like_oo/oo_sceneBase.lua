-- if you want create a scene , 
local scene_base = class( "sceneBase" , require("app.like_oo.oo_viewBase") );

scene_base.m_type = 1;

function scene_base:createView(  )
	-- body
	cclog(" ------ scene_base:create ---- " .. self.__cname)
	self.m_rootView = cc.Layer:create();
	if(self.m_control.onTouch)then
		local function onTouch( eventType, x, y )
			-- body
			-- cclog(" ------------ yock ");
			-- cclog("------------- eventType " .. eventType);
            return self.m_control:onTouch(eventType , x , y);
		end
		self.m_rootView:registerScriptTouchHandler(onTouch,false, 1 ,true);
		self.m_rootView:setTouchEnabled(true);
	end
	self:onCreate();
	return self.m_rootView;
end

function scene_base:destroy(  )
	-- body
	cclog("-------- destroy view " .. self.m_control.m_data:getName());
	
end

function scene_base:consumeTouch( con )
	-- body
	self.m_rootView:setTouchEnabled(con);
end

return scene_base;