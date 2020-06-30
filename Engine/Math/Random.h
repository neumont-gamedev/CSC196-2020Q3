#pragma once
#include <random>

namespace nc
{
	float random()
	{
		return rand() / static_cast<float>(RAND_MAX); // 0 - RAND_MAX ->  0 / 10 = 0 | 5 / 10 = 0.5 | 10 / 10 = 1
	}

	float random(float min, float max) // 6.0 - 10.0
	{
		if (min > max)
		{
			std::swap(min, max);
		}
		return min + ((max - min) * random()); // 0 - 4
	}
}