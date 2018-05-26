local login_control = class("loginControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function login_control:onCreate(  )
	-- body
end

function login_control:onEnter(  )
	-- body
end

function login_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:closeView();
		self:setHomeName("mainscene")
		self:openView("mainscene")
	end
	if(msg == 'print')then
		print(data);
	end
end

function login_control:onUpdate(  )
	-- body
end

return login_control;