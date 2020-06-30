#pragma once

//#include <cmath>
//#include <random>

namespace nc
{
	const float PI = 3.1415f;
	const float TWO_PI = PI * 2.0f;
	const float HALF_PI = PI * 0.5f;

	const float DEG_TO_RAD = PI / 180.0f;
	const float RAD_TO_DEG = 180.0f / PI;

	//template <typename T>
	//T max(const T& a, const T& b)
	//{
	//	return (a < b ? b : a);
	//}

	//template <typename T>
	//T min(const T& a, const T& b)
	//{
	//	return (a < b ? a : b);
	//}

	//template <typename T>
	//inline T clamp(T v, T low, T high)
	//{
	//	return std::min<T>(high, std::max<T>(v, low));
	//}

	//template <typename T>
	//inline T clamp01(T v)
	//{
	//	return std::min<T>(1, std::max<T>(v, 0));
	//}
}
