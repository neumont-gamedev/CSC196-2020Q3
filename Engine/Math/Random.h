#pragma once

//#include <limits>
//#include <random>

namespace nc
{
	void random_seed(int seed)
	{
		srand(seed);
	}

	int random(int max)
	{
		return rand() % max;
	}

	int random(int min, int max)
	{
		if (min > max)
		{
			std::swap(min, max);
		}

		return min + rand() % ((max - min) + 1);
	}

	float random()
	{
		return rand() / static_cast<float>(RAND_MAX);
	}

	float random(float min, float max)
	{
		if (min > max)
		{
			std::swap(min, max);
		}

		return min + (max - min) * random();
	}
}
