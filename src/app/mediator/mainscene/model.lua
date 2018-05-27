local mainscene_model = class("mainsceneModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function mainscene_model:onCreate(  )
	-- body
	-- self:getData(game_url.getUrlForKey("entrance")); 
	self:getData();
end

function mainscene_model:onEnter(  )
	-- body
end

return mainscene_model;