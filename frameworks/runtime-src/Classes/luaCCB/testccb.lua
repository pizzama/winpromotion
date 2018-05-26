-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    local cclog = function(...)
        print(string.format(...))
    end

    require "hello2"
    cclog("result is " .. myadd(3, 5))

    ---------------


    -- create ui with ccbi file
    -- call back function when button click
    local function onClick2(sender,controlEvent)
        cclog("onClick2 be call event is" .. controlEvent);
    end
    -- create a node
    local ccbNode = luaCCBNode:create();
    -- register a function with name
    ccbNode:registerFunctionWithFuncName("onClick2",onClick2);
    -- open the ccbi file
    ccbNode:openCCBFile("HelloCocosBuilder.ccbi");

    -- play background music, preload effect

    -- uncomment below for the BlackBerry version
    -- local bgMusicPath = CCFileUtils:sharedFileUtils():fullPathFromRelativePath("background.ogg")
    local bgMusicPath = CCFileUtils:sharedFileUtils():fullPathFromRelativePath("background.mp3")
    SimpleAudioEngine:sharedEngine():playBackgroundMusic(bgMusicPath, true)
    local effectPath = CCFileUtils:sharedFileUtils():fullPathFromRelativePath("effect1.wav")
    SimpleAudioEngine:sharedEngine():preloadEffect(effectPath)


    -- run
    local sceneGame = CCScene:create()
    -- sceneGame:addChild(createLayerFarm())
    -- sceneGame:addChild(createLayerMenu())
    -- add node in scene
    sceneGame:addChild(ccbNode);
    CCDirector:sharedDirector():runWithScene(sceneGame)
    
end

xpcall(main, __G__TRACKBACK__)
