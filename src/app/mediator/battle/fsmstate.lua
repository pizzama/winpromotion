local state = class("state");

function state:onCreate()
	-- body
	self:getData()
end

function state:onEnter()

end

return state;