#include "EventsHandler.h"





void registerButtonTables(lua_State* state) {
	//Input class
	lua_createtable(state, 0, 0);
	lua_pushliteral(state, "KeyCode");
	lua_createtable(state, 0, 5);
	lua_pushnumber(state, -1);
	lua_setfield(state, -2, "Unknown");

#pragma region A-Z
	//A-Z
	lua_pushstring(state, "A");
	lua_setfield(state, -2, "A");

	lua_pushstring(state, "B");
	lua_setfield(state, -2, "B");

	lua_pushstring(state, "C");
	lua_setfield(state, -2, "C");

	lua_pushstring(state, "D");
	lua_setfield(state, -2, "D");

	lua_pushstring(state, "E");
	lua_setfield(state, -2, "E");

	lua_pushstring(state, "F");
	lua_setfield(state, -2, "F");

	lua_pushstring(state, "G");
	lua_setfield(state, -2, "G");

	lua_pushstring(state, "H");
	lua_setfield(state, -2, "H");

	lua_pushstring(state, "I");
	lua_setfield(state, -2, "I");

	lua_pushstring(state, "J");
	lua_setfield(state, -2, "J");

	lua_pushstring(state, "K");
	lua_setfield(state, -2, "K");

	lua_pushstring(state, "L");
	lua_setfield(state, -2, "L");

	lua_pushstring(state, "M");
	lua_setfield(state, -2, "M");

	lua_pushstring(state, "N");
	lua_setfield(state, -2, "N");

	lua_pushstring(state, "O");
	lua_setfield(state, -2, "O");

	lua_pushstring(state, "P");
	lua_setfield(state, -2, "P");

	lua_pushstring(state, "Q");
	lua_setfield(state, -2, "Q");

	lua_pushstring(state, "R");
	lua_setfield(state, -2, "R");

	lua_pushstring(state, "S");
	lua_setfield(state, -2, "S");

	lua_pushstring(state, "T");
	lua_setfield(state, -2, "T");

	lua_pushstring(state, "U");
	lua_setfield(state, -2, "U");

	lua_pushstring(state, "V");
	lua_setfield(state, -2, "V");

	lua_pushstring(state, "W");
	lua_setfield(state, -2, "W");

	lua_pushstring(state, "X");
	lua_setfield(state, -2, "X");

	lua_pushstring(state, "Y");
	lua_setfield(state, -2, "Y");

	lua_pushstring(state, "Z");
	lua_setfield(state, -2, "Z");
	//END A-Z
#pragma endregion

#pragma region Numbers
	lua_pushstring(state, "Num0");
	lua_setfield(state, -2, "Num0");

	lua_pushstring(state, "Num1");
	lua_setfield(state, -2, "Num1");

	lua_pushstring(state, "Num2");
	lua_setfield(state, -2, "Num2");

	lua_pushstring(state, "Num3");
	lua_setfield(state, -2, "Num3");

	lua_pushstring(state, "Num4");
	lua_setfield(state, -2, "Num4");

	lua_pushstring(state, "Num5");
	lua_setfield(state, -2, "Num5");

	lua_pushstring(state, "Num6");
	lua_setfield(state, -2, "Num6");

	lua_pushstring(state, "Num7");
	lua_setfield(state, -2, "Num7");

	lua_pushstring(state, "Num8");
	lua_setfield(state, -2, "Num8");

	lua_pushstring(state, "Num9");
	lua_setfield(state, -2, "Num9");

#pragma endregion

#pragma region Numpads
	lua_pushstring(state, "Numpad0");
	lua_setfield(state, -2, "Numpad0");

	lua_pushstring(state, "Numpad1");
	lua_setfield(state, -2, "Numpad1");

	lua_pushstring(state, "Numpad2");
	lua_setfield(state, -2, "Numpad2");

	lua_pushstring(state, "Numpad3");
	lua_setfield(state, -2, "Numpad3");

	lua_pushstring(state, "Numpad4");
	lua_setfield(state, -2, "Numpad4");

	lua_pushstring(state, "Numpad5");
	lua_setfield(state, -2, "Numpad5");

	lua_pushstring(state, "Numpad6");
	lua_setfield(state, -2, "Numpad6");

	lua_pushstring(state, "Numpad7");
	lua_setfield(state, -2, "Numpad7");

	lua_pushstring(state, "Numpad8");
	lua_setfield(state, -2, "Numpad8");

	lua_pushstring(state, "Numpad9");
	lua_setfield(state, -2, "Numpad9");
#pragma endregion

#pragma region Others
	lua_pushstring(state, "Escape");
	lua_setfield(state, -2, "Escape");

	lua_pushstring(state, "LeftControl");
	lua_setfield(state, -2, "LeftControl");

	lua_pushstring(state, "RightControl");
	lua_setfield(state, -2, "RightControl");

	lua_pushstring(state, "LeftShift");
	lua_setfield(state, -2, "LeftShift");

	lua_pushstring(state, "RightShift");
	lua_setfield(state, -2, "RightShift");

	lua_pushstring(state, "LeftAlt");
	lua_setfield(state, -2, "LeftAlt");

	lua_pushstring(state, "RightAlt");
	lua_setfield(state, -2, "RightAlt");

	lua_pushstring(state, "LeftSystem");
	lua_setfield(state, -2, "LeftSystem");

	lua_pushstring(state, "RightSystem");
	lua_setfield(state, -2, "RightSystem");

	lua_pushstring(state, "Menu");
	lua_setfield(state, -2, "Menu");

	lua_pushstring(state, "LeftBracket");
	lua_setfield(state, -2, "LeftBracket");

	lua_pushstring(state, "RightBracket");
	lua_setfield(state, -2, "RightBracket");

	lua_pushstring(state, "Semicolon");
	lua_setfield(state, -2, "Semicolon");

	lua_pushstring(state, "Comma");
	lua_setfield(state, -2, "Comma");

	lua_pushstring(state, "Period");
	lua_setfield(state, -2, "Period");

	lua_pushstring(state, "Quote");
	lua_setfield(state, -2, "Quote");

	lua_pushstring(state, "Slash");
	lua_setfield(state, -2, "Slash");

	lua_pushstring(state, "Backslash");
	lua_setfield(state, -2, "Backslash");

	lua_pushstring(state, "Tilde");
	lua_setfield(state, -2, "Tilde");

	lua_pushstring(state, "Equal");
	lua_setfield(state, -2, "Equal");

	lua_pushstring(state, "Hyphen");
	lua_setfield(state, -2, "Hyphen");

	lua_pushstring(state, "Space");
	lua_setfield(state, -2, "Space");

	lua_pushstring(state, "Enter");
	lua_setfield(state, -2, "Enter");

	lua_pushstring(state, "Backspace");
	lua_setfield(state, -2, "Backspace");

	lua_pushstring(state, "Tab");
	lua_setfield(state, -2, "Tab");

	lua_pushstring(state, "PageUp");
	lua_setfield(state, -2, "PageUp");

	lua_pushstring(state, "PageDown");
	lua_setfield(state, -2, "PageDown");

	lua_pushstring(state, "End");
	lua_setfield(state, -2, "End");

	lua_pushstring(state, "Home");
	lua_setfield(state, -2, "Home");

	lua_pushstring(state, "Insert");
	lua_setfield(state, -2, "Insert");

	lua_pushstring(state, "Delete");
	lua_setfield(state, -2, "Delete");

	lua_pushstring(state, "Add");
	lua_setfield(state, -2, "Add");

	lua_pushstring(state, "Subtract");
	lua_setfield(state, -2, "Subtract");

	lua_pushstring(state, "Multiply");
	lua_setfield(state, -2, "Multiply");

	lua_pushstring(state, "Divide");
	lua_setfield(state, -2, "Divide");
#pragma endregion

#pragma region Arrows
	lua_pushstring(state, "Up");
	lua_setfield(state, -2, "Up");

	lua_pushstring(state, "Down");
	lua_setfield(state, -2, "Down");

	lua_pushstring(state, "Left");
	lua_setfield(state, -2, "Left");

	lua_pushstring(state, "Right");
	lua_setfield(state, -2, "Right");
#pragma endregion

#pragma region Functions
	lua_pushstring(state, "F1");
	lua_setfield(state, -2, "F1");

	lua_pushstring(state, "F2");
	lua_setfield(state, -2, "F2");

	lua_pushstring(state, "F3");
	lua_setfield(state, -2, "F3");

	lua_pushstring(state, "F4");
	lua_setfield(state, -2, "F4");

	lua_pushstring(state, "F5");
	lua_setfield(state, -2, "F5");

	lua_pushstring(state, "F6");
	lua_setfield(state, -2, "F6");

	lua_pushstring(state, "F7");
	lua_setfield(state, -2, "F7");

	lua_pushstring(state, "F8");
	lua_setfield(state, -2, "F8");

	lua_pushstring(state, "F9");
	lua_setfield(state, -2, "F9");

	lua_pushstring(state, "F10");
	lua_setfield(state, -2, "F10");

	lua_pushstring(state, "F11");
	lua_setfield(state, -2, "F11");

	lua_pushstring(state, "F12");
	lua_setfield(state, -2, "F12");
#pragma endregion

	lua_settable(state, 1);
	lua_setglobal(state, "Input");
	
}