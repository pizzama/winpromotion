--- util 工具类

local M = {};

-- 打印table
function M.print_lua_table(self,lua_table)
  cc.log("====================================================================")
  if type(lua_table) == "table" then
     cc.log(self:stringTable(lua_table,""))
  else
     cc.log("lua_table ====="..tostring(lua_table))
  end
  cc.log("====================================================================")
end
-- 返回table的string格式
function M.stringTable(self,t, lh)
    if type(t)=="table" then
        local hs="  ";
        if lh then
            hs = lh.."  ";
        end
        local line_h = "\n"..hs;
        local str="{"
        local flag = false;
        for k,v in pairs(t) do
            if flag then
                str=str..",";
            end
            if type(k)=="number" then
                str = str..line_h.."["..k.."] = ";
            else
                str = str..line_h..k.." = ";
            end
            if type(v)=="table" then
                str = str..(self:stringTable(v, hs));
            elseif type(v)=="string" then
                str = str.."\""..v.."\"";
            else
                str = str..tostring(v)
            end
            flag = true;
        end
        str = str.."\n"..lh.."}";
        return str;
    else
        return tostring(t)
    end
end

function M.getClippingRectAnimNode(width,height)
    local clippingNode = CCClippingNode:create()
    clippingNode:setAnchorPoint(cc.p(0.5, 0))
    clippingNode:setInverted(false)
    clippingNode:setAlphaThreshold(1)
    -- 遮罩图片
    local stencilLayer = CCLayerColor:create(cc.c4b(255,255,255, 0), width, height)
    stencilLayer:ignoreAnchorPointForPosition(false)
    stencilLayer:setAnchorPoint(cc.p(0.5, 0) )
    stencilLayer:setPosition(cc.p(width/2, 0))
    clippingNode:setStencil(stencilLayer)
    clippingNode:setContentSize(stencilLayer:getContentSize())
    return clippingNode
end
--裁剪NODE
function M.getClippingRectNode(width,height)
    local clippingNode = CCClippingNode:create()
    clippingNode:setAnchorPoint(cc.p(0.5, 0))
    clippingNode:setInverted(false)
    clippingNode:setAlphaThreshold(1)
    -- 遮罩图片
    local stencilLayer = CCLayerColor:create(cc.c4b(255,255,255, 0), width, height+100)
    stencilLayer:ignoreAnchorPointForPosition(false)
    stencilLayer:setAnchorPoint(cc.p(0.5, 0) )
    stencilLayer:setPosition(cc.p(width/2, -100))
    clippingNode:setStencil(stencilLayer)
    clippingNode:setContentSize(stencilLayer:getContentSize())
    return clippingNode
end

function M.ceil( num )
    -- body
    local temp = math.floor(num);
    if(num>0)then
        if(temp<num)then
            temp = temp+1;
        end
    else
        if(temp>num)then
            temp = temp-1;
        end
    end
    return temp;
end

function M.url_encode(str)
  if (str) then
    str = string.gsub (str, "\n", "\r\n")
    str = string.gsub (str, "([^%w ])",
        function (c) return string.format ("%%%02X", string.byte(c)) end)
    str = string.gsub (str, " ", "+")
  end
  return str
end

function M.url_decode(str)
  str = string.gsub (str, "+", " ")
  str = string.gsub (str, "%%(%x%x)",
      function(h) return string.char(tonumber(h,16)) end)
  str = string.gsub (str, "\r\n", "\n")
  return str
end

function M.readFileByBuff(fileName,buffSize)
	local BUFSIZE = 2^13 -- 8K
	if buffSize ~= nil and type(buffSize) == "number" then
    	BUFSIZE = buffSize;
    end
    local f = io.input(fileName) -- open input file
    if f == nil then return "" end
    local cc, lc, wc = 0, 0, 0 -- char, line, and word counts
    local readData = "";
    while true do
        local lines, rest = f:read(BUFSIZE, "*line")
        if not lines then break end
        -- print("lines = " .. lines);
        -- print("rest = " .. rest);
        -- cclog("string len string.len(lines) = " .. string.len(lines) .. " ; string.len(rest) = " .. string.len(rest));
        if rest then readData = readData .. lines .. rest .. '\n' end
        cc = cc + string.len(lines)
        -- count words in the chunk
        local _,t = string.gsub(lines, "%S+", "")
        wc = wc + t
        -- count newlines in the chunk
        _,t = string.gsub(lines, "\n", "\n")
        lc = lc + t
    end
    cclog("lc = " .. lc .. " ; wc = " .. wc .. " ; cc = " .. cc);
    return readData;
end

function M.writeFile(self,fileName,content,mode)
    cc.FileUtils:getInstance():writeStringToFile(content,fileName);
    -- io.writefile(fileName,content,mode)
end

function M:stringSplit(str, splitChar)
    local sub_str_tab = {};
    while (true) do
        local pos = string.find(str, splitChar);
        if (not pos) then
            sub_str_tab[#sub_str_tab + 1] = str;
            break;
        end
        local sub_str = string.sub(str, 1, pos - 1);
        sub_str_tab[#sub_str_tab + 1] = sub_str;
        str = string.sub(str, pos + 1, #str);
    end
    return sub_str_tab;
end

function M.saveStringTable( fname,ptable )
    -- body
    local wfile = util_file:new();
    local f = "local tempTable = {\n";
    local a = "}\n\nreturn tempTable;";
    if(wfile:Open(fname,16))then
        wfile:Write(f,string.len(f));
        local str = nil;
        for k,v in pairs(ptable) do
            str = "\"" .. v .. "\",\n";
            wfile:Write(str,string.len(str));
        end
        wfile:Write(a,string.len(a));
        wfile:Close();
    else
        -- cclog("--- saveStringTable can not open file");
    end
    wfile:delete();
end


--- 屏蔽字处理
function M.maskWordCheck(str)
    local words = gameConfig:getCfgByName("ping")
    local times = 0
    local nowStr = str
    if nowStr then
        for i,v in ipairs(words) do
            for ii,vv in ipairs(v) do
                local replaceStr = string.gsub(vv, "[%z\1-\127\194-\244][\128-\191]*", "*")
                local subTimes = 0
                nowStr, subTimes = string.gsub(nowStr, vv, replaceStr)
                times = times + subTimes
            end
        end
    end
    return nowStr, times
end

-- 检测字符串是否由英文、数字、空白符组成
function M.regularCharNumBlank(str)
    local plain = string.find(str,"[^%w%s]")
    if plain then
        return true
    else
        return false
    end
end

-- 检测字符串是否由中文、英文、数字、空白符组成
function M.regularChineseCharNumBlank(str) 
    local plain = string.find(str,"[^%w%s\128-\191\194-\244]")
    if plain then
        return true
    else
        local chineseChar = gameConfig:getCfgByName("pingbizifu")
        for i,v in ipairs(chineseChar) do
            for ii,vv in ipairs(v) do
                local plain = string.find(str,vv)
                if plain then
                    return true
                end
            end
        end
        return false
    end
end

return M;
