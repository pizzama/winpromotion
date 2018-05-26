-- 一些常量
SERVER_IP = "192.168.1.34" --34
SERVER_PORT = "20012"
RES_SERVER = "http://192.168.6.109:8080/zip/"
CLIENT_VERSION = "1.0.03"
VERSION = "v1.0001"
SERVER_VERSION = ""
UPDATE_URL = RES_SERVER
local writablePath = cc.FileUtils:getInstance():getWritablePath();
--入口地址
MASTER_URL_IP = "http://192.168.2.47:8989/genesis" -- 内网开发环境
print("   writablePath =======    ", writablePath)

---游戏配置
GAMECONFIG=
{
    isUseCustomLogin=true,--是否使用自己的登录框
    isShowCenter=false,--是否显示平台的按钮
    isShowRelogin=true, -- 是否显示重登陆的按钮
    isShowQuitBtn=true, -- 是否显示退出按钮
    logoutType="0", --0注销后从新进入游戏,1注销后进入到登陆界面
    push_channel_id="",  -- 百度推送channelid
    platformname="",--平台名称
    mac="",--客户端的mac地址
    identifier=nil,--客户端的identifier
    appVersion=nil,--客户端版本号
    appBuild=nil,--客户端构建版本号

    --游戏服务器返回的数据
    sdkToken="",
    openname="",
    sdkuserid="",
    username="",
    code="",
    notifyUrl = nil
}

