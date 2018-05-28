local sceneman = class("sceneman",function ()
	return cc.Layer:create()
end);

function sceneman:ctor(image,pos)
	self.man = cc.Sprite:create(image);
    self.man:setPosition(pos)
    self:addChild(self.man);
    local function onTouch( eventType, x, y )
        if eventType == "began" then
            local pt = self:convertToNodeSpace(cc, p(x, y));
            if self.man:getBoundingBox().containsPoint(pt) then
                local act = cc.TintBy:create(2, -150, -150, -150);
                self.man:runAction(cc.RepeatForever:create(cc.Sequence:create({act,act:reverse()})))
                return true;
            else
                return false;     
            end
        elseif(eventType == "ended")then
            self.man:setColor(cc.c3b(255,255,255));
            self.man:stopAllActions();
        end
    end
    self:registerScriptTouchHandler(onTouch,false, 0,true);
    self:setTouchEnabled(true);
end

return sceneman

