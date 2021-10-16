#pragma once
#include <string>
using namespace std;

#include <stdio.h>
#include <iostream>

extern "C" {
#include "Lua/include/lua.h",
#include "Lua/include/lauxlib.h",
#include "Lua/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua/liblua54.a")
#endif

#include "SFML/Graphics.hpp"
using namespace sf;

#include "GameWindow.h"



void registerButtonTables(lua_State* state);