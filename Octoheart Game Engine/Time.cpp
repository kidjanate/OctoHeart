

#include "Time.h"
#include "TimeGame.h"
#include <iostream>
#include <string>

#include <chrono>

using namespace std;
using namespace OctoHeart::Time;


void TimeGame::Start() {
	StartTime = std::chrono::system_clock::now().time_since_epoch().count();
	
}

int64_t TimeGame::currentTime() {
	return std::chrono::system_clock::now().time_since_epoch().count() - StartTime;
}




void TimeGame::deltaTime() {
	
	y = std::chrono::system_clock::now().time_since_epoch().count();

	delta = y - x;
	x = std::chrono::system_clock::now().time_since_epoch().count();	

	//cout << OctoHeart::Time::delta << endl;
}

int64_t TimeGame::getDeltaTime() {
	return delta;
}