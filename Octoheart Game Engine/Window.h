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

#include <SFML/Graphics.hpp>
using namespace sf;

#include "GameWindow.h"
#include <Windows.h>

static int SetTitle(lua_State* L) {
	string title = lua_tostring(L, 1);
	MainWindow.setTitle(title);
	return 0;
}

static int SetSize(lua_State* L) {
	int x = lua_tointeger(L, 1);
	int y = lua_tointeger(L, 2);
	MainWindow.setSize(Vector2u(x, y));
	return 0;
}

static int Close(lua_State* L) {
	MainWindow.close();
	return 0;
}

static int ShowConsole(lua_State* L) {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOW);
	return 0;
}

static int HideConsole(lua_State* L) {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
	return 0;
}