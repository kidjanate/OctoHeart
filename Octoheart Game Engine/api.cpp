#include <string>
using namespace std;

#include <stdio.h>
#include <iostream>
#include <thread>

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


#include "Time.h"
#include "TimeGame.h"
#include "GameWindow.h"
#include "Object.h"

#include "Window.h"
#include "EventsHandler.h"

static int DrawObject(lua_State * L) {
	string type = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	int sx = lua_tonumber(L, 4);
	int sy = lua_tonumber(L, 5);
	int rotate = lua_tonumber(L, 6);

	
	CreateObject(MainWindow, type, x, y, sx, sy, rotate);
	return 0;
}


using namespace OctoHeart::Time;

static int Print(lua_State* L) {
	bool b = lua_toboolean(L, 1);
	string s = lua_tostring(L, 1);
	cout << s << endl;
	return 0;
}

static int Wait(lua_State* L) {
	bool b = lua_toboolean(L, 1);
	int s = lua_tonumber(L, 1);
	std::this_thread::sleep_for(chrono::milliseconds(s));
	return 0;
}




class API {
public:
	lua_State* state;
	bool runStart = false;
	bool runUpdate = false;
	

	int CompileLuaWithPath(string path) {
		state = luaL_newstate();
		luaL_openlibs(state);
		int r = luaL_dofile(state, path.c_str());

		
		

		if (r == LUA_OK) {
			Setup();
		}
		else {
			string err = lua_tostring(state, -1);
			printf(("[Lua] " + path + " Error\n" + err).c_str());
		}
		return 0;
	}

public:
	void CallStart() {
		if (!runStart)
			return;
		int start = lua_getglobal(state, "Start");
		if (start != 0) {
			if (lua_isfunction(state, -1)) {
				lua_call(state, 0, 0);
			}
		}
	}

public:
	void CallUpdate() {
		//Sync deltaTime
		OctoHeart::Time::TimeGame::deltaTime();
		
		
		

		if (!runUpdate)
			return;
		int update = lua_getglobal(state, "Update");
		if (update != 0) {
			if (lua_isfunction(state, -1)) {
				int64_t dt = OctoHeart::Time::TimeGame::getDeltaTime();
				lua_pushinteger(state, dt);
				lua_call(state, 1, 0);
			}


		}
		
	}



	

	void Setup() {
		OctoHeart::Time::TimeGame::Start();

		//print
		//lua_register(state, "print", Print);
		lua_register(state, "CreateObject", DrawObject);

		lua_register(state, "wait", Wait);

		//Events
		//Input
		registerButtonTables(state);

		WindowClass();

		CheckError();
	}

	void WindowClass() {
		//Window Class
		lua_createtable(state, 0, 5);

		lua_pushcfunction(state, SetTitle);
		lua_setfield(state, -2, "SetTitle");

		lua_pushcfunction(state, SetSize);
		lua_setfield(state, -2, "SetSize");

		lua_pushcfunction(state, Close);
		lua_setfield(state, -2, "Close");

		lua_pushcfunction(state, ShowConsole);
		lua_setfield(state, -2, "ShowConsole");

		lua_pushcfunction(state, HideConsole);
		lua_setfield(state, -2, "HideConsole");

		lua_setglobal(state, "Window");
	}

	void CheckError() {

		//Start function
		int start = lua_getglobal(state, "Start");
		if (start != 0) {
			if (!lua_isfunction(state, -1)) {
				printf("[Lua] Warning : \"Start\" must be the function\n");
			}
			else {
				runStart = true;
			}
		}
		else {
			printf("[Lua] Warning : Missing \"Start\" function\n");
		}

		//Update function
		int update = lua_getglobal(state, "Update");
		if (update != 0) {
			if (!lua_isfunction(state, -1)) {
				printf("[Lua] Warning : \"Update\" must be the function\n");
			}
			else {
				runUpdate = true;
			}
		}
		else {
			printf("[Lua] Warning : Missing \"Update\" function\n");
		}

	}

	void OnKeyPressed(sf::Event* Event) {
		int fun = lua_getglobal(state, "OnKeyDown");
		if (fun != 0) {
			if (lua_isfunction(state, -1)) {
				lua_getglobal(state, "OnKeyDown");

				returnButton(Event);


				lua_call(state, 1, 0);
			}
		}
	}

	void OnKeyReleased(sf::Event* Event) {
		int fun = lua_getglobal(state, "OnKeyUp");
		if (fun != 0) {
			if (lua_isfunction(state, -1)) {
				lua_getglobal(state, "OnKeyUp");

				returnButton(Event);


				lua_call(state, 1, 0);
			}
		}
	}

	void returnButton(sf::Event* Event) {
		
		switch (Event->key.code) {
		case Keyboard::Unknown:
			lua_pushnumber(state,-1);
			break;
			//Nightmare Here
#pragma region A-Z
		case Keyboard::A:
			lua_pushstring(state, "A");
			break;

		case Keyboard::B:
			lua_pushstring(state, "B");
			break;

		case Keyboard::C:
			lua_pushstring(state, "C");
			break;

		case Keyboard::D:
			lua_pushstring(state, "D");
			break;

		case Keyboard::E:
			lua_pushstring(state, "E");
			break;

		case Keyboard::F:
			lua_pushstring(state, "F");
			break;

		case Keyboard::G:
			lua_pushstring(state, "G");
			break;

		case Keyboard::H:
			lua_pushstring(state, "H");
			break;

		case Keyboard::I:
			lua_pushstring(state, "I");
			break;

		case Keyboard::J:
			lua_pushstring(state, "J");
			break;

		case Keyboard::K:
			lua_pushstring(state, "K");
			break;

		case Keyboard::L:
			lua_pushstring(state, "L");
			break;

		case Keyboard::M:
			lua_pushstring(state, "M");
			break;

		case Keyboard::N:
			lua_pushstring(state, "N");
			break;

		case Keyboard::O:
			lua_pushstring(state, "O");
			break;

		case Keyboard::P:
			lua_pushstring(state, "P");
			break;

		case Keyboard::Q:
			lua_pushstring(state, "Q");
			break;

		case Keyboard::R:
			lua_pushstring(state, "R");
			break;

		case Keyboard::S:
			lua_pushstring(state, "S");
			break;

		case Keyboard::T:
			lua_pushstring(state, "T");
			break;

		case Keyboard::U:
			lua_pushstring(state, "U");
			break;

		case Keyboard::V:
			lua_pushstring(state, "V");
			break;

		case Keyboard::W:
			lua_pushstring(state, "W");
			break;

		case Keyboard::X:
			lua_pushstring(state, "X");
			break;

		case Keyboard::Y:
			lua_pushstring(state, "Y");
			break;

		case Keyboard::Z:
			lua_pushstring(state, "Z");
			break;
#pragma endregion

#pragma region Numbers
		case Keyboard::Num0:
			lua_pushstring(state, "Num0");
			break;

		case Keyboard::Num1:
			lua_pushstring(state, "Num1");
			break;

		case Keyboard::Num2:
			lua_pushstring(state, "Num2");
			break;

		case Keyboard::Num3:
			lua_pushstring(state, "Num3");
			break;

		case Keyboard::Num4:
			lua_pushstring(state, "Num4");
			break;

		case Keyboard::Num5:
			lua_pushstring(state, "Num5");
			break;

		case Keyboard::Num6:
			lua_pushstring(state, "Num6");
			break;

		case Keyboard::Num7:
			lua_pushstring(state, "Num7");
			break;

		case Keyboard::Num8:
			lua_pushstring(state, "Num8");
			break;

		case Keyboard::Num9:
			lua_pushstring(state, "Num9");
			break;

#pragma endregion

#pragma region Numpads
		case Keyboard::Numpad0:
			lua_pushstring(state, "Numpad0");
			break;

		case Keyboard::Numpad1:
			lua_pushstring(state, "Numpad1");
			break;

		case Keyboard::Numpad2:
			lua_pushstring(state, "Numpad2");
			break;

		case Keyboard::Numpad3:
			lua_pushstring(state, "Numpad3");
			break;

		case Keyboard::Numpad4:
			lua_pushstring(state, "Numpad4");
			break;

		case Keyboard::Numpad5:
			lua_pushstring(state, "Numpad5");
			break;

		case Keyboard::Numpad6:
			lua_pushstring(state, "Numpad6");
			break;

		case Keyboard::Numpad7:
			lua_pushstring(state, "Numpad7");
			break;

		case Keyboard::Numpad8:
			lua_pushstring(state, "Numpad8");
			break;

		case Keyboard::Numpad9:
			lua_pushstring(state, "Numpad9");
			break;
#pragma endregion

#pragma region Others
		case Keyboard::Escape:
			lua_pushstring(state, "Escape");
			break;

		case Keyboard::LControl:
			lua_pushstring(state, "LeftControl");
			break;

		case Keyboard::RControl:
			lua_pushstring(state, "RightControl");
			break;

		case Keyboard::LShift:
			lua_pushstring(state, "LeftShift");
			break;

		case Keyboard::RShift:
			lua_pushstring(state, "RightShift");
			break;

		case Keyboard::LAlt:
			lua_pushstring(state, "LeftAlt");
			break;

		case Keyboard::RAlt:
			lua_pushstring(state, "RightAlt");
			break;

		case Keyboard::LSystem:
			lua_pushstring(state, "LeftSystem");
			break;

		case Keyboard::RSystem:
			lua_pushstring(state, "RightSystem");
			break;

		case Keyboard::Menu:
			lua_pushstring(state, "Menu");
			break;

		case Keyboard::LBracket:
			lua_pushstring(state, "LeftBracket");
			break;

		case Keyboard::RBracket:
			lua_pushstring(state, "RightBracket");
			break;

		case Keyboard::Semicolon:
			lua_pushstring(state, "Semicolon");
			break;

		case Keyboard::Comma:
			lua_pushstring(state, "Comma");
			break;

		case Keyboard::Period:
			lua_pushstring(state, "Period");
			break;

		case Keyboard::Quote:
			lua_pushstring(state, "Quote");
			break;

		case Keyboard::Slash:
			lua_pushstring(state, "Slash");
			break;

		case Keyboard::Backslash:
			lua_pushstring(state, "Backslash");
			break;

		case Keyboard::Tilde:
			lua_pushstring(state, "Tilde");
			break;

		case Keyboard::Equal:
			lua_pushstring(state, "Equal");
			break;

		case Keyboard::Hyphen:
			lua_pushstring(state, "Hyphen");
			break;

		case Keyboard::Space:
			lua_pushstring(state, "Space");
			break;

		case Keyboard::Enter:
			lua_pushstring(state, "Enter");
			break;

		case Keyboard::Backspace:
			lua_pushstring(state, "Backspace");
			break;

		case Keyboard::Tab:
			lua_pushstring(state, "Tab");
			break;

		case Keyboard::PageUp:
			lua_pushstring(state, "PageUp");
			break;

		case Keyboard::PageDown:
			lua_pushstring(state, "PageDown");
			break;

		case Keyboard::End:
			lua_pushstring(state, "End");
			break;

		case Keyboard::Home:
			lua_pushstring(state, "Home");
			break;

		case Keyboard::Insert:
			lua_pushstring(state, "Insert");
			break;

		case Keyboard::Delete:
			lua_pushstring(state, "Delete");
			break;

		case Keyboard::Add:
			lua_pushstring(state, "Add");
			break;

		case Keyboard::Subtract:
			lua_pushstring(state, "Subtract");
			break;

		case Keyboard::Multiply:
			lua_pushstring(state, "Multiply");
			break;

		case Keyboard::Divide:
			lua_pushstring(state, "Divide");
			break;
#pragma endregion
		
#pragma region Arrows
		case Keyboard::Up:
			lua_pushstring(state, "Up");
			break;

		case Keyboard::Down:
			lua_pushstring(state, "Down");
			break;

		case Keyboard::Left:
			lua_pushstring(state, "Left");
			break;

		case Keyboard::Right:
			lua_pushstring(state, "Right");
			break;
#pragma endregion

#pragma region Functions
		case Keyboard::F1:
			lua_pushstring(state, "F1");
			break;

		case Keyboard::F2:
			lua_pushstring(state, "F2");
			break;

		case Keyboard::F3:
			lua_pushstring(state, "F3");
			break;

		case Keyboard::F4:
			lua_pushstring(state, "F4");
			break;

		case Keyboard::F5:
			lua_pushstring(state, "F5");
			break;

		case Keyboard::F6:
			lua_pushstring(state, "F6");
			break;

		case Keyboard::F7:
			lua_pushstring(state, "F7");
			break;

		case Keyboard::F8:
			lua_pushstring(state, "F8");
			break;

		case Keyboard::F9:
			lua_pushstring(state, "F9");
			break;

		case Keyboard::F10:
			lua_pushstring(state, "F10");
			break;

		case Keyboard::F11:
			lua_pushstring(state, "F11");
			break;

		case Keyboard::F12:
			lua_pushstring(state, "F12");
			break;
#pragma endregion


		}
	}
};




