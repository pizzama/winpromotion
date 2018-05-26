local update_control = class("updateControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function update_control:onCreate(  )
	-- body
end

function update_control:onEnter(  )
	-- body
end

function update_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:closeView();
	end
	if(msg == 'print')then
		print(data);
	end
end

function update_control:onUpdate(  )
	-- body
end

return update_control;