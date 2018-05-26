
local battleView = class("battleView", __G_REQUIRE("app.like_oo.oo_sceneBase"));
__G_REQUIRE("app.shared.extcocos2d")
local ship = __G_REQUIRE("app.ui.battle.ship");

function battleView:onCreate()
    self.sp = ship.new()
    self.sp:setPosition(cc.p(200,200))
    self.sp:moveSpeed(1);
    self.sp:moveMaxSpeed(2);
    self.sp:moveAngle(math.pi/4)
    self.m_rootView:addChild(self.sp)
end

function battleView:fly(evt)
    local et = tolua.cast(evt,"cc.EventCustom");
    local target = tolua.cast(et:getUserData(),"JoystickEvent");
    local x = target:getX();
    local y = target:getY();
    local t = target:getType();
    print("the touch:::" .. tostring(t));
    self.sp:moveAngle(target:getAngle());
    self.sp:moveSpeed(2);
    -- self.sp:updateEntity()
end

function battleView:onEnter()
    local bg = CCSprite:create("joystick_bg.png");
    local cen = CCSprite:create("joystick_center.png");
    local stick = cc.Joystick:create(bg,cen,"event_of_joystick");
    stick:setPosition(cc.p(100,100))
    self.m_rootView:addChild(stick)

    local joylistener = cc.EventListenerCustom:create("event_of_joystick",handler(self,self.fly))
    local customEventDispatch=cc.Director:getInstance():getEventDispatcher()
    customEventDispatch:addEventListenerWithFixedPriority(joylistener,1)

    -- --------------- 触摸处理函数 -----------------
    -- local function touchFunc(event, x, y)
    --     -- body
    --     if event == cc.TOUCH_EVENT_BEGAN then
    --         return true
    --     elseif event == cc.TOUCH_EVENT_MOVED then
    --         return true
    --     elseif event == cc.TOUCH_EVENT_ENDED then
    --         self.touchx = x;
    --         self.touchy = y;
    --         -- local pt = self.node:convertToNodeSpace(cc.p(x, y))
    --         -- local pos = screenToIso(point2d.new(pt.x,pt.y))
    --         -- print(tostring(pos));
    --     else  -- 触摸取消
    --     end
    -- end

    -- self.m_rootView:registerScriptTouchHandler(touchFunc)
    self.m_rootView:addNodeEventListener(cc.NODE_ENTER_FRAME_EVENT, handler(self,self.update))
    self.m_rootView:scheduleUpdate()
end

function battleView:update()
    -- self.sp:wander();
    -- self.sp1:updateEntity()
    self.sp:updateEntity()
end

function battleView:destroy()
    self.super.destroy(self)
end

return battleView;
