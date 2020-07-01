#pragma once

// NOMINMAX

namespace nc
{
	const float PI = 3.1415f;
	const float TWO_PI = PI * 2;

	template<typename T> const T& min(const T& a, const T& b) { return (a > b) ? b : a; }
	template<typename T> const T& max(const T& a, const T& b) { return (a > b) ? a : b; }

	template<typename T> T clamp(const T& value, const T& min, const T& max) 
	{ 
		//return (value < min) ? min : (value > max) ? max : value;

		if (value < min) return min;
		if (value > max) return max;

		return value;
	}

	template<> Vector2 clamp<Vector2>(const Vector2& value, const Vector2& min, const Vector2& max)
	{
		Vector2 result = value;

		result.x = clamp(result.x, min.x, max.x);
		result.y = clamp(result.y, min.y, max.y);

		return result;
	}

	template<typename T> T lerp(const T& a, const T& b, float s)
	{
		return a + ((b - a) * s);
	}
}



