#pragma once

namespace nc
{
	struct Vector2
	{
		float x;
		float y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}

		void set(float x, float y) { this->x = x; this->y = y; }

		float  operator [] (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }

		// relational operator
		bool operator == (const Vector2& v) const { return x == v.x && y == v.y; }
		bool operator != (const Vector2& v) const { return x != v.x || y != v.y; }

		// assignment operator
		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }

		Vector2& operator += (float s) { x += s; y += s; return *this; }
		Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s; y /= s; return *this; }

		// arithmetic operator
		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); }

		Vector2 operator + (float s) const { return { x + s, y + s }; }
		Vector2 operator - (float s) const { return { x - s, y - s }; }
		Vector2 operator * (float s) const { return { x * s, y * s }; }
		Vector2 operator / (float s) const { return { x / s, y / s }; }

		// negate vector
		Vector2 operator - () const { return { -x, -y }; }
	};
}
