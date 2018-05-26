local game_url = 
{
	entrance = "/entrance/?",
}
--[[--
    获得完整的url
]]
function game_url.getUrlForKey(key)
    local url = nil;
    if game_url[key] then
        --后段说加这个参数
        local sid = sid
        if sid then
            url = MASTER_URL_IP .. game_url[key].."&sid="..sid;
        else
            url = MASTER_URL_IP .. game_url[key];
        end
    end
    if url ~= nil then
        local params = {
            url,
            "user_token=" .. "",
            "pt=" .. GAMECONFIG.platformname,
            "channel_id=" .. (GAMECONFIG.channel_id or ""),
            "device_mark=" .. "",
            "version=" .. CLIENT_VERSION,
            "__ts=" .. tostring(os.time()),
        }
        if GAMECONFIG.platformname ~= nil  then
            table.insert(params,"platform_channel=" .. tostring(GAMECONFIG.platformname));
        end

        if GAMECONFIG.identifier ~= nil then
            table.insert(params,"identifier=" .. tostring(GAMECONFIG.identifier));
        end


        if GAMECONFIG.appVersion ~= nil then
            table.insert(params,"appversion=" .. tostring(GAMECONFIG.appVersion));
        end
        if GAMECONFIG.appBuild ~= nil then
            table.insert(params,"appbuild=" .. tostring(GAMECONFIG.appBuild));
        end

        if GAMECONFIG.devicename ~= nil then
           table.insert(params,"devicename=" .. tostring(GAMECONFIG.devicename)); 
        end



        url = url .. "&user_token=" .. "" .. "&mk=" .. "";
        url = table.concat(params, "&")
    end
    return url;
end

return game_url;