#pragma once
#include <chrono>

class DeltaTime
{
public:
	DeltaTime();
	float Mark();
private:
	std::chrono::steady_clock::time_point storeTime;
};