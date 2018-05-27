local mainscene_control = class("mainsceneControl",__G_REQUIRE("app.like_oo.oo_controlBase"));

function mainscene_control:onCreate(  )
	-- body
end

function mainscene_control:onEnter(  )
	-- body
	self:openView("mainscene/main",{opentype="home"})
end

function mainscene_control:onHandle( msg , data )
	-- body
	if(msg == 1)then
		self:openView("mainscene/cityscene")
	end
	if(msg == 'print')then
		print(data);
	end
end

function mainscene_control:onUpdate(  )
	-- body
end

return mainscene_control;