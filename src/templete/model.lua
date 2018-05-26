local test_model = class("testModel",__G_REQUIRE("app.like_oo.oo_dataBase"));

function test_model:onCreate(  )
	-- body
	self:getData();
end

function test_model:onEnter(  )
	-- body
	self.m_data = nil;
	self.m_params = nil;
end

return test_model;