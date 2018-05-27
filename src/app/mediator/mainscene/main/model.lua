local mainscene_main_model = class("mainscene_main_Model",__G_REQUIRE("app.like_oo.oo_dataBase"));

function mainscene_main_model:onCreate(  )
	-- body
	self:getData();
end

function mainscene_main_model:onEnter(  )
	-- body
end

return mainscene_main_model;