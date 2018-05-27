local citycene_control = class("citysceneControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function citycene_control:onCreate(  )
	-- body
end

function citycene_control:onEnter(  )
	-- body
	self:openView("mainscene/main",{opentype="city"})
end

function citycene_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:closeView();
	end
	if(msg == 'print')then
		print(data);
	end
end

function citycene_control:onUpdate(  )
	-- body
end

return citycene_control;