local data_base = class( "dataBase" , nil );

data_base.m_netWork = require("app.shared.network");
data_base.m_control = nil;				-- the handle with frame's control
data_base.m_name = nil;					-- the frame name
data_base.m_alias = nil;				-- the frame alias
data_base.m_data = nil;					-- nomorl data with net or native
data_base.m_params = nil;				-- the frame's params that control function openViews second param
-- 1 is a first data
-- 2 is a histroy data for back to
data_base.m_type = 1;
data_base.transfer = ""; --专场方式scale or fade

--[[
异／同步方法，获得getData获得的数据
data : type is lua table
]]
function data_base:callBack( data )
	-- body
	self.m_data = data;
	local tempControl = __G_RELOAD("app.mediator."..self.m_name .. ".control"):new();
	tempControl.m_data = self;
	tempControl.m_model = self;
	self:onEnter();
	tempControl:createControl();
	self.m_control = tempControl;
	-- util.printf( data );
end

function data_base:getLoacalData(teamid,guideId,key,params_)

	local data      =  game_guide_controller:getLocalFile(guideId,key)
	local alignment = data['alignment']
    if alignment then
        game_data:setTeamData(alignment);
    end
	--返点等级
	if guideId == 501 then
		game_data.m_tUserStatusData['level'] = 5
	elseif guideId == 503 then
		game_data.m_tUserStatusData['level'] = 5
	elseif  guideId == 404 or guideId == 403 then
		print("guideId ======403")
		game_data.m_tUserStatusData['level'] = 4
	elseif guideId == 409 then
		game_data.m_tUserStatusData['level'] = 4
	end
	game_data:setUserStatusDataByJsonData(data["user_status"]);
	if game_guide_controller.show_name == nil then
		game_guide_controller.show_name = string_config.m_show_name
	end
	game_data.m_tUserStatusData['show_name'] = string_config.m_show_name

	game_data.m_tUserStatusData['character_role'] = 9001
	
	game_data:clientCacheUpdate(data["_client_cache_update"]);

	self:callBack( data );
	-------------保存返点-------------
	game_guide_controller:saveGuidePoint(teamid ,guideId )
	if params_ then
    	--------------保存返点--------------
	    if  params_.guide then
	    	game_data:saveLocalData(teamid,params_.guide)
	    elseif params_.step then
	    	game_data:saveLocalData(teamid,params_.step)
	    end
	end
end

--[[
根据key得到数据，
key ＝ "http://"开头时，是网络数据,否则为本地数据
params_ 为网络请求参数，可以没有
]]
function data_base:getData( key , params_, requestMethod,tag)
	-- body
	if( self.m_data~=nil )then
		self:callBack( self.m_data );
		return;
	end
	if(key~=nil and string.find( key , "http://"))then
		local function responseMethod(data)
			if(data == nil )then
				if(self.m_type == 2)then
					static_pageList:addData( self );
				end
			else
            	self:callBack( data );
            end
		end
		requestMethod = requestMethod or "GET"
		self.m_netWork:sendHttpRequest( responseMethod , key , requestMethod , params_);
	else
		if(key==nil)then
			self:callBack(nil);
		else
			local data = getConfigTable( key );
			if(data~=nil)then
				-- data = __json.decode(data:getFormatBuffer());
				self:callBack( data );
			else
				self:callBack( nil );
			end
		end
	end
end

-- 获得本地数据，没有回调
function data_base:getNativeData( file, filetype)
	-- body
	local tempData = nil;
	if filetype == "json" then
		local rt = cc.FileUtils:getInstance():getStringFromFile(file);
		if rt == "" or rt == nil then
			cclog("Error could't get the file content:" .. tostring(file))
			return nil;
		end
		tempData = json.decode(rt)
	elseif filetype == "lua" then

	elseif filetype == "xml" then
	
	end
	return tempData;
end

function data_base:writeNativeData(file,content,mode)
	local path = cc.FileUtils:getInstance():getWritablePath()
	path = path .. file
	local typefile = type(content);
	if typefile == "table" then
		content = util:stringTable(content,"")
	end
	util:writeFile(path,content,mode)
end

-- 获取网络数据，有回调
--[[
	loadingFlag true 会显示小loading
	            false 没有任何loading
]]
function data_base:getNetData( key , params_ , callfunc ,returnFlag, requestMethod)
	-- body
	local function responseMethod(data,event)
		if(data ~= nil)then
        	if(callfunc)then
       			callfunc(data);
       		end
       	else
       		if(callfunc)then
    			callfunc(nil);
        	end
        end
    end
	requestMethod = requestMethod or "GET"
	
	self.m_netWork:sendHttpRequest( responseMethod , key , requestMethod , params_ );
end


-- 获得当前view框架名字
function data_base:getName(  )
	-- body
	return self.m_name;
end

-- 获得当前view框架别名
function data_base:getAlias(  )
	-- body
	return self.m_alias;
end

--[[
data_base默认启动接口
]]
function data_base:createModel( name , params , alias )
	-- body
	self.m_name = name;
	self.m_params = params;
	self.m_alias = alias;
	self:onCreate();
end

--[[
默认销毁接口
]]
function data_base:destroy(  )
	-- body
	cclog("----------- destroy model " .. self:getName());

end

-- ============================================ a little cut of line ================================

function data_base:onCreate(  )
	-- body
	cclog("------------------ model onCreate " .. self.m_name);
end

function data_base:onEnter(  )
	-- body
	cclog("------------------ model onEnter " .. self.m_name);
end


return data_base;
