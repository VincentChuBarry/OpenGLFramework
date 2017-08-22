#pragma once
#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(const float& x, const float& y);
	Vector2 operator +(const Vector2& other);
	Vector2 operator -(const Vector2& other);
	Vector2 operator *(const Vector2& other);
	Vector2 operator /(const Vector2& other);
	Vector2& operator +=(const Vector2& other);
	Vector2& operator -=(const Vector2& other);
	Vector2& operator *=(const Vector2& other);
	Vector2& operator /=(const Vector2& other);
	bool operator ==(const Vector2& other);
	bool operator !=(const Vector2& other);
public:
	float m_x;
	float m_y;
};
