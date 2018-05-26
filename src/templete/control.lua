local test_control = class("testControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function test_control:onCreate(  )
	-- body
end

function test_control:onEnter(  )
	-- body
end

function test_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:closeView();
	end
	if(msg == 'print')then
		print(data);
	end
end

function test_control:onUpdate(  )
	-- body
end

return test_control;