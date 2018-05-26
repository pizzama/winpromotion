local login_model = class("loginModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function login_model:onCreate(  )
	-- body
	-- self:getData(game_url.getUrlForKey("entrance")); 
	self:getData();
end

function login_model:onEnter(  )
	-- body
	-- cclog(self.m_data)
	self.m_params = nil;
end

return login_model;