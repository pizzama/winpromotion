local function isClassOrObject( obj )
    -- body
    return obj.new ~= nil;
end

local control_base = class( "controlBase" , nil );

local util = __G_REQUIRE("app.shared.util");

-- message data list
control_base.m_msg = nil;		
-- run loop with message data
control_base.m_enterId = nil;
-- map with chiled controller
control_base.m_chilrenList = nil;
-- model for this control
control_base.m_data = nil;
control_base.m_model = nil;
-- view with self
control_base.m_view = nil;
-- mind perant control
control_base.m_parent = nil;
-- need save data for goBack
control_base.m_needBack = true;
-- timer list
control_base.m_timerList = nil;

-- static var with root control
static_rootControl = nil;
-- static var that with histroy page list
static_pageList = __G_REQUIRE("app.like_oo.oo_stack"):new();
-- home name
static_homeName = "";


-- static front layer
static_frontLayer = nil;
-- static normal layer
static_normalLayer = nil;
-- ghost pop
static_ghostChildren = nil;

-- 
function control_base:createControl(  )

	-- body
	cclog("----------- control_base:create " .. self.m_data:getName());
	self.m_msg = __G_REQUIRE("app.like_oo.oo_msgList"):new();
	self.m_chilrenList = {};
	self.m_timerList = {};
	local freecount = 1;

	local function tick( dt )
		-- body
		-- cclog("--- control_base tick all " .. self.__cname .. " " .. tostring(dt));
		-- local temp = 1;
		for tk,tv in pairs(self.m_timerList) do
			-- cclog("------- temp " .. tostring(temp));
			-- temp = temp+1;
			tv.time = tv.time+dt;
			-- cclog("-------- control_base tick " .. self.__cname .. " " .. tostring(tv.time));
			if(tv.inter<=0)then
				tv.callFunc( self , tv.time );
				tv.time = 0;
			elseif(tv.time>=tv.inter)then
				tv.callFunc( self , tv.inter );
				tv.time = tv.time-tv.inter;
			end
		end

		--【Fix】新号每次创建角色会报self.msg不存在错误
		if not self.m_msg then return cclog("controlBase self.msg is nil!") end 
		local tempMsg = self.m_msg:pop()
		if not tempMsg then return end

		if( tempMsg.m_msg == "oo_update")then
			if( static_rootControl~=nil )then
				static_rootControl:onUpdate();
				for k,v in pairs(static_rootControl.m_chilrenList) do
					if(not isClassOrObject(v))then
						for kc,vc in pairs(v) do
							vc:onUpdate();
						end
					else
						v:onUpdate();
					end
				end
			end
		else
			self:onHandle( tempMsg.m_msg , tempMsg.m_data );
		end
	end
	self.m_enterId = scheduler.registerSchedule(tick, 1/60.0, false)
	self:onCreate();
	local tempType = self:createView();
	self:onUpdate();
	self.m_view:onEnter();
	self:onEnter();

	-- 析构内存资源
	local function deleteTexture()
		display.removeUnusedSpriteFrames()
	end
    scheduler.performWithDelay(deleteTexture, 1.0/60)

	if(self.m_model:getName() == static_homeName)then
		static_pageList:cleanAll();
	end
	return tempType;
end

function control_base:onDestroy()

end

-- 
function control_base:destroy(  )
	-- body
	cclog("--------- destroy control " .. self.m_model:getName());
	self:onDestroy();

	if self.m_enterId ~= nil then
        scheduler.unschedule(self.m_enterId)
        self.m_enterId = nil;
    end
    -- message data list
    if(self.m_msg)then
    	self.m_msg:cleanAll();
	end
	self.m_msg = nil;		
	-- run loop with message data
	self.m_enterId = nil;
	-- map with chiled controller
	-- local childCount = #self.m_chilrenList;

	for k,v in pairs(self.m_chilrenList) do
		if(not isClassOrObject(v))then
			for k,v in pairs(v) do
				v:closeView();
			end
		else
			v:closeView();
		end
	end

	if(self.m_view)then
		self.m_view:destroy();
	end

	if(self.m_data)then
		self.m_data:destroy();
	end


	-- mind perant control
	if(self.m_parent ~= nil)then
		local tempChiled = self.m_parent.m_chilrenList[self.m_data:getName()];
		if(not isClassOrObject(tempChiled))then
			self.m_parent.m_chilrenList[self.m_data:getName()][self.m_data:getAlias()] = nil;
			if(util.table_len(self.m_parent.m_chilrenList[self.m_data:getName()])<=0)then
				self.m_parent.m_chilrenList[self.m_data:getName()] = nil;
			end
		else
			self.m_parent.m_chilrenList[self.m_data:getName()] = nil;
		end
		self.m_parent = nil;
	end
	-- model for this control
	self.m_data = nil;
	-- view with self
	self.m_view = nil;

	for k,v in pairs(self.m_timerList) do
		self.m_timerList[k] = nil;
	end

end

-- 构造view用
function control_base:createView(  )
	local tempname = "app.mediator." .. self.m_data:getName() .. ".view"
	local viewCls
	if LUA_RELOAD_DEBUG then
		viewCls = __G_RELOAD(tempname)
	else
		viewCls = __G_REQUIRE(tempname)
	end
	self.m_view = viewCls:new();
	self.m_view.m_control = self;
	local tempV = self.m_view:createView();
	if(tempV~=nil)then
		local tempVT = self.m_view:getType();
		if(tempVT == 1)then
			if(static_rootControl)then
				if(self.m_data.m_type == 1)then	-- if data type is a first flag
					if static_rootControl.m_needBack and static_rootControl.m_data then
						static_rootControl.m_data.m_type = 2;
						static_pageList:addData(static_rootControl.m_data);
					end
				elseif(self.m_data.m_type == 2)then	-- if data type is a histroy flag
					static_rootControl.m_data:destroy();
				end
				static_rootControl:destroy();
			else
				self:init_oo();
			end

			self.m_parent = nil;
			static_rootControl = self;

			self:replaceScene(tempV);
		elseif(tempVT == 2)then
			-- add pop in the control
			local normalFlag = self.m_view.m_normal;
			if(not normalFlag)then
				self.m_parent = nil;
				if(not static_ghostChildren)then
					static_ghostChildren = {};
				end
				local tempName = self.m_data:getName();
				if(static_ghostChildren[tempName]~=nil)then
					cclog("---------- closeView");
					static_ghostChildren[tempName]:closeView();
				end
				static_ghostChildren[tempName] = self;
				static_frontLayer:addChild(tempV);
			else
				if(static_rootControl)then
					self.m_parent = static_rootControl;
					self:getRootWin():addChild(tempV , self.m_view.m_priority);
					if(static_rootControl.m_chilrenList[self.m_data:getName()]~=nil)then
						local tempName = self.m_data:getName();
						local tempAlias = self.m_data:getAlias();
						local tempC = static_rootControl.m_chilrenList[tempName];
						if( not isClassOrObject(tempC))then
							if(tempAlias == nil)then
								local tempAl = #tempC+1;
								tempC[tempAl] = self;
								self.m_data.m_alias = tempAl;
							else
								tempC[tempAlias] = self;
							end
						else
							static_rootControl.m_chilrenList[tempName] = {};
							local alias = tempC.m_data:getAlias();

							if(alias == nil)then
								static_rootControl.m_chilrenList[tempName][1] = tempC;
								tempC.m_data.m_alias = 1;
							else
								static_rootControl.m_chilrenList[tempName][alias] = tempC;
							end

							local tempCR = static_rootControl.m_chilrenList[tempName];
							if(tempAlias == nil)then
								local tempAl = #tempCR+1;
								tempCR[tempAl] = self;
								self.m_data.m_alias = tempAl;
							else
								tempCR[tempAlias] = self;
							end
						end
					else
						static_rootControl.m_chilrenList[self.m_data:getName()] = self;
					end
				end
			end
		end
		return tempVT;
	end
	return nil;
end



--[[
	打开指定名字的窗口

]]
function control_base:openView( name , params , alias, ismulity)
	-- body
	--todo 如果是model状态则只能打开一个。多余的会关掉。
	if (ismulity == nil or ismulity == false) then
		local result = self:hasChild(name,alias)
		if result == true then
			return;
		end
	end

	local namepath = string.gsub(name,"%.","/");
	local fileFullPath = cc.FileUtils:getInstance():fullPathForFilename("src/app/mediator/" .. namepath .. "/model.lua");
	local tempHasF = cc.FileUtils:getInstance():isFileExist(fileFullPath)
	if(tempHasF)then
		local tempname = "app.mediator." .. name .. ".model";
		cclog("-------------- openView:" .. tempname );

		local tempCls
		if LUA_RELOAD_DEBUG then 
			tempCls = __G_RELOAD(tempname)
		else
			tempCls = __G_REQUIRE(tempname);
		end

		local tempModel = tempCls:new();
		tempModel:createModel( name , params , alias );
	else
		cclog("-------------- not find " .. name);
	end
end

function control_base:closeView( name , alias )
	-- body
	if(name)then

		local tempChiled = static_rootControl.m_chilrenList[name];
		if(tempChiled)then
			-- if(type(tempChiled) == "table")then
			if(not isClassOrObject(tempChiled))then
				if(alias)then
					local tempAliasC = tempChiled[alias];
					if(tempAliasC)then
						tempAliasC:closeView();
						static_rootControl.m_chilrenList[name][alias] = nil;
						if(util.table_len(static_rootControl.m_chilrenList[name][alias])<=0)then
							static_rootControl.m_chilrenList[name] = nil;
						end
					end
				else
					for k,v in pairs(tempChiled) do
						v:closeView();
					end
					static_rootControl.m_chilrenList[name] = nil;
				end
			else
				tempChiled:closeView();
				static_rootControl.m_chilrenList[name] = nil;
			end
		elseif(static_ghostChildren~=nil and static_ghostChildren[name]~=nil)then
			static_ghostChildren[name]:closeView();
			static_ghostChildren[name] = nil;
		end
	else
		self:destroy();
	end
end

--[[
更新一个消息到消息队列中
msg :消息标记
data:为消息数据
flag:为数据传递标志
	 'this'   当前control消息
	 'parent' 父control消息
	 '其他'   指定名字control消息
]]
function control_base:updateMsg( msg , data , flag , alias )
	-- body
	local temp = { m_msg = msg , m_data = data };
	if(flag == 'this' or flag == nil)then
		if self.m_msg == nil then return end;
		self.m_msg:addMsg( temp );
	elseif(flag == 'parent')then
		if(self.m_parent)then
			self.m_parent:updateMsg( msg, data , 'this' );
		elseif(static_rootControl)then
				static_rootControl:updateMsg( msg, data , 'this');
		else
			self.m_msg:addMsg(temp)
		end
	else
		if(static_rootControl.m_chilrenList[flag] ~= nil)then
			cclog("---------- yock chilren " .. flag);
			local tempChilren = static_rootControl.m_chilrenList[flag];
			-- if(type(tempChilren) == "table")then
			if(not isClassOrObject(tempChilren))then
				if(alias)then
					if(tempChilren[alias] ~= nil)then
						tempChilren[alias]:updateMsg( msg , data , 'this' );
					else
						for k,v in pairs(tempChilren) do
							print(k);
						end
						cclog("---------- yock no chilren " .. flag .. "alias=" .. alias);
					end
				else
					cclog("----------- updateMsg all chiled " .. flag);
					for k,v in pairs(tempChilren) do
						v:updateMsg(msg , data , 'this');	
					end
				end
			else
				static_rootControl.m_chilrenList[flag]:updateMsg( msg , data , 'this' );
			end
		elseif(static_ghostChildren~=nil and static_ghostChildren[flag]~=nil)then
			static_ghostChildren[flag]:updateMsg( msg , data , 'this' );
		else

			for k,v in pairs(static_rootControl.m_chilrenList) do
				print(k);
			end
			cclog("---------- yock no chilren " .. flag);
		end
	end

end

--[[
	发出一个更新全族消息
]]
function control_base:updateView(  )
	-- body
	if(static_rootControl~=nil)then
		static_rootControl:updateMsg("oo_updata");
	end
end

--[[
	检查是否可以回退
	返回值：true   可以返回
		   false  不可以返回
]]

function control_base:canBack(  )
	-- body
	if(static_pageList:hasData())then
		return true;
	else
		return false;
	end
end

--[[
	返回上一个页面
	从历史数据里取得最后一个压栈数据
	还原视图
	duress: 强制重新拿数据，从onCreate开始 true
]]
function control_base:goBack( duress )
	-- body
	if(not self:canBack())then
		return;
	end
	local tempModel = static_pageList:pop();
	if(tempModel.m_name == static_homeName)then
		static_pageList:cleanAll();
	end
	-- 
	tempModel.m_type = 2;
	if(duress == nil or duress == false)then
		tempModel:callBack(tempModel.m_data);
	else
		tempModel.m_data = nil;
		tempModel:onCreate();
	end

end

--[[
	设置返回重点页面
]]
function control_base:setHomeName( homeName )
	-- body
	static_homeName = homeName;
end


--[[
	获得根窗口
	根窗口为静态变量
]]
function control_base:getRootWin(  )
	-- body
	local tempRC = self:getRootControl();
	if(tempRC ~= nil)then
		return tempRC.m_view:getRootView();
	else
		return nil;
	end
end

--[[
	得到根控制器（control）
]]
function control_base:getRootControl(  )
	-- body
	return static_rootControl;
end


--[[
	注册timer回调函数
]]
function control_base:setTimer( interval,onTimer )
	-- body
	local tempTimer = { time = 0 , inter = interval , callFunc = onTimer };
	local id = #self.m_timerList+1;
	self.m_timerList[id] = tempTimer;
	return id;
end

--[[
	移出timer回调
]]
function control_base:removeTimer( id )
	-- body
	print("m_timerList:" .. tostring(self.m_timerList));
	if self.m_timerList[id] ~= nil then
		self.m_timerList[id]=nil;	
	end
end

--[[
	检查是否有指定子窗口
]]
function control_base:hasChild( name , alias )
	-- body
	--如果是空的话则还没有常见view。所以肯定没有子窗口
	if static_rootControl == nil then
		return false;
	end

	local tempChilren = static_rootControl.m_chilrenList[name];
	if(tempChilren ~= nil)then
		if(alias == nil)then
			return true;
		else
			if(not isClassOrObject(tempChilren))then
				if(tempChilren[alias] ~= nil)then
					return true;
				else
					return false;
				end
			else
				return false;
			end
		end
	elseif(static_ghostChildren~=nil and static_ghostChildren[name]~=nil)then
		return true;
	end
	return false;
end


-- ================================= a cut of line =================================

-- 构造结束后调用

function control_base:onCreate(  )
	-- body
	cclog("------------- control onCreate " .. self.m_data:getName());
end

-- 构造结束后调用
function control_base:onEnter(  )
	-- body
	cclog("------------- control onEnter " .. self.m_data:getName());
	
end

-- 消息循环重载后使用
function control_base:onHandle( msg , data )
	-- body
end

function control_base:onUpdate(  )
	-- body
end


-- ================================= a cut of line =================================

--[[
	释放内存
]]
function control_base:freeMemory(  )
	-- body
	print("the scene free memory");
	cc.SpriteFrameCache:sharedSpriteFrameCache():removeUnusedSpriteFrames();
	cc.TextureCache:sharedTextureCache():removeUnusedTextures();
	-- CCTextureCache:sharedTextureCache():dumpCachedTextureInfo();
end

function control_base:freeAllMemory()
	cc.SpriteFrameCache:sharedSpriteFrameCache():removeSpriteFrames();
	cc.TextureCache:sharedTextureCache():removeAllTextures();
end

--[[
	融合小伍框架用
	返回首页
]]
function control_base:goHome(  )
	-- body
	-- local function callBackFunc()
	-- 	self:destroy();
	-- 	static_rootControl = nil;
	-- end
	-- game_scene:enterGameUi("game_main_scene",{gameData = nil},{endCallFunc = callBackFunc});
end

function control_base:init_oo(  )
	-- body
	local s = cc.Scene:create();
	local front = cc.Layer:create();
	local normal = cc.Layer:create();
	s:addChild(normal);
	s:addChild(front);
	static_frontLayer = front;
	static_normalLayer = normal;
	display.runScene(s);
end

--[[
	
	切换场景
]]
function control_base:replaceScene( scene )
	-- body
	static_normalLayer:removeAllChildren(true);
	local function scriptEvent( eventType )
	-- 	-- body
		if(eventType == 'cleanup')then
			cclog("---------------- remove resource");
			cc.SpriteFrameCache:sharedSpriteFrameCache():removeUnusedSpriteFrames();
			cc.TextureCache:sharedTextureCache():removeUnusedTextures();
		end
	end
	scene:registerScriptHandler(scriptEvent);
	static_normalLayer:addChild(scene);
end


return control_base;



