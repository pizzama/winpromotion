local breakSocketHandle,debugXpCall = require("lua_debugger.LuaDebugjit")("localhost",7004)

luaDebuggerTick = breakSocketHandle
luaDebuggerXpCall = debugXpCall