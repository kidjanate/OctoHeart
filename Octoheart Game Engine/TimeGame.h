#pragma once
#include <chrono>

namespace OctoHeart {
	namespace Time {
		class TimeGame {
		public:
			static void Start();
			static int64_t currentTime();
			static void deltaTime();
			static int64_t getDeltaTime();
		};
	}
}