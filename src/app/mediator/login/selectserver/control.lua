local selectserver_control = class("selectserverControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function selectserver_control:onCreate(  )
	-- body
end

function selectserver_control:onEnter(  )
	-- body
end

function selectserver_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:closeView();
	end
	if(msg == 'print')then
		print(data);
	end
end

function selectserver_control:onUpdate(  )
	-- body
end

return selectserver_control;