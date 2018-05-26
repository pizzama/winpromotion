local mainscene_model = class("mainsceneModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function mainscene_model:onCreate(  )
	-- body
	-- self:getData(game_url.getUrlForKey("entrance")); 
	self:getData();
end

function mainscene_model:onEnter(  )
	-- body
	-- cclog(self.m_data)

	local dt = self:getNativeData("config/login.conf","json")
	local ta = {1,2,3}
	self:writeNativeData("login.tmp",ta);
	self.m_params = nil;
end

return mainscene_model;