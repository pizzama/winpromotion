local network = class("network",{});

function network:sendHttpRequest(callback,url,method,params)
    --处理参数(如果参数是表，那么再拆分一次 只支持一层)

    local xhr = cc.XMLHttpRequest:new() --创建一个请求  
    xhr.responseType = cc.XMLHTTPREQUEST_RESPONSE_JSON --设置返回数据格式为字符串  
    if method == "GET" then
        local pa = "";
        if params ~= nil then
            if type(params) == "table" then
                for k, v in pairs(params) do
                    if type(v) == "table" then              -- 如果参数是表，那么再拆分一次 只支持一层
                        for kk, vv in pairs(v) do
                            pa = pa .. k .. "=" .. vv .. "&";
                        end
                    else
                        pa = pa .. k .. "=" .. v .. "&";
                    end
                end
            elseif type(params) == "string" then
                pa = params;
            end
        end
        if pa ~= "" then
            url = url .. "&" .. pa;
        end
    else
        for k,v in params do
            xhr:setRequestHeader(tostring(k),tostring(v));
        end
    end
    local req = url --请求地址  
    xhr:open(method, req) --设置请求方式  GET     或者  POST  
      
    local function onReadyStateChange()  --请求响应函数  
        if xhr.readyState == 4 and (xhr.status >= 200 and xhr.status < 207) then --请求状态已完并且请求已成功  
                local statusString = "Http Status Code:"..xhr.statusText  
                print("请求返回状态码"..statusString)
                local s = xhr.response --获得返回的内容  
                print("返回的数据")
                if callback then
                    callback(xhr.response)
                end
        end  
    end  
    xhr:registerScriptHandler(onReadyStateChange) --注册请求响应函数  
    xhr:send() --最后发送请求 
end

return network;