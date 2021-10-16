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



void CreateObject(RenderWindow & win, string shape, int x, int y, int scaleX, int scaleY, int rotate);


//static vector<OctoHeart::GameObject::GameObject> AllGameObject;
