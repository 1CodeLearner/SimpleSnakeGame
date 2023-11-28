#include "DeltaTime.h"

using namespace std::chrono;
DeltaTime::DeltaTime()
{
	storeTime = steady_clock::now();
}

float DeltaTime::Mark()
{
	steady_clock::time_point oldTime = storeTime;
	auto newTime = steady_clock::now();
	storeTime = newTime;
	auto deltaTime = duration<float>(newTime - oldTime);
	return deltaTime.count();
}
