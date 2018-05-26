local update_model = class("updateModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function update_model:onCreate(  )
	-- body
	self.m_data = 5;
	self:getData();
end

function update_model:onEnter(  )
	-- body
	self.m_data = nil;
	self.m_params = nil;
end

return update_model;