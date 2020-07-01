#pragma once

namespace nc
{
	struct Vector2
	{
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}

		float& operator [] (size_t index) { return (&x)[index]; }
		const float& operator [] (size_t index) const { return (&x)[index]; }

		void Set(float x, float y) { this->x = x; this->y = y; }

		Vector2 operator + (const Vector2& v) const { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ x / v.x, y / v.y }; }

		Vector2 operator + (float s) const { return Vector2{ x + s, y + s }; }
		Vector2 operator - (float s) const { return Vector2{ x - s, y - s }; }
		Vector2 operator * (float s) const { return Vector2{ x * s, y * s }; }
		Vector2 operator / (float s) const { return Vector2{ x / s, y / s }; }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }

		Vector2& operator += (float s) { x += s; y += s; return *this; }
		Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s; y /= s; return *this; }

		Vector2 operator - () const { return Vector2{ -x, -y };	}

		float Length() const;
		static float Distance(const Vector2& v1, const Vector2& v2);

		Vector2 Normalized();
		void Normalize();
	};

	inline float Vector2::Length() const
	{
		return std::sqrt(x * x + y * y);
	}

	inline float Vector2::Distance(const Vector2& v1, const Vector2& v2)
	{
		Vector2 v = v1 - v2;
		return v.Length();
	}

	inline Vector2 Vector2::Normalized()
	{
		float length = Length();
		Vector2 n = (length == 0.0f) ? Vector2{0, 0} : (*this / length);

		return n;
	}

	inline void Vector2::Normalize()
	{
		float length = Length();
		if (length == 0.0f)
		{
			*this = Vector2{ 0, 0 };
		}
		else
		{
			*this /= length;
		}
	}

}