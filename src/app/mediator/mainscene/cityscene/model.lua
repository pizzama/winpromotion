local cityscene_model = class("citysceneModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function cityscene_model:onCreate(  )
	-- body
	-- self:getData(game_url.getUrlForKey("entrance")); 
	self:getData();
end

function cityscene_model:onEnter(  )

end

return cityscene_model;