local util = require("app.shared.util");


local M = class("dataCatch",nil);

local function changeTo( data1,data2 )
	-- body
	local beChanged = false;
	for k,v in pairs(data2) do
		if(data1[k] == nil or type(data1[k]) ~= type(v))then
			print("the data format possibly changes");
			data1[k] = v;
			beChanged = true;
		else
			if(type(v) == "table")then
				beChanged = (changeTo(data1[k],v) or beChanged);
			else
				if(data1[k] ~= v)then
					data1[k] = v;
					beChanged = true;
				end
			end	
		end
	end
end

-- create memory catch with name
function M:createCatch( name,data )
	-- body
	M[name] = data;
end

function M:get( name )
	-- body
	local temp = M[name];
	if(temp == nil)then
		print("get " .. name .. " is nil");
		return nil;
	end
	if(type(temp) == "table")then
		return util.table_copy(temp);
	else
		return temp;
	end
end

function M:save( name,data )
	-- body

	if(M[name] == nil)then
		print(name .. " is nil");
		return false;
	end

	if(type(M[name]) ~= type(data))then
		print("the data that name is " .. name .. " format possibly changes , res=" .. type(M[name]) .. "," .. "des=" .. type(data));
	end

	if(type(data) ~= "table" or type(M[name]) ~= "table")then
		if(data == M[name])then
			return false;
		else
			M[name] = data;
			return true;
		end
	end

	return changeTo(M[name],data);

end

function M:release( name )
	-- body
	M[name] = nil;
end

function M:releaseAll(  )
	-- body
	for k,v in pairs(self) do
		if(type(v) ~= "function")then
			self[k] = nil;
		end
	end
end



return M;