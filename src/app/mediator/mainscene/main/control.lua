local mainscene_main_control = class("mainscene_main_Control",__G_REQUIRE("app.like_oo.oo_controlBase"));

function mainscene_main_control:onCreate(  )
	-- body
end

function mainscene_main_control:onEnter(  )
	-- body
end

function mainscene_main_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		if self.m_model.m_params.opentype == "home" then
			self:openView("mainscene/cityscene")
		elseif self.m_model.m_params.opentype == "city" then
			self:openView("mainscene")
		end
	end
	if(msg == 'print')then
		print(data);
	end
end

function mainscene_main_control:onUpdate(  )
	-- body
end

return mainscene_main_control;