#include <SFML/Graphics.hpp>

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <iostream>

#include <list>



//Game
#include "GameWindow.h"
#include "api.cpp"
#include "EventsHandler.h"
#include "Object.h"
#include <thread>


int main()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	//Show Window
	MainWindow.create(VideoMode(512, 512),"OctoHeart");
	MainWindow.setKeyRepeatEnabled(false);


	API api;
	api.CompileLuaWithPath("main.lua");
	api.CallStart();




	
	while (MainWindow.isOpen())
	{
		sf::Event Event;
		while (MainWindow.pollEvent(Event)) {
			switch (Event.type)
			{
			case sf::Event::Closed:
				MainWindow.close();
				break;
			case sf::Event::KeyPressed:
				api.OnKeyPressed(&Event);
				break;
			case sf::Event::KeyReleased:
				api.OnKeyReleased(&Event);
				break;
			default:
				break;
			}



		}
		
		MainWindow.clear();
		api.CallUpdate();
		
		MainWindow.display();
		

		
	}

	return 0;

	
}

