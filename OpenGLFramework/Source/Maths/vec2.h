#pragma once
#include <iostream>

class vec2
{
public:
	vec2();
	vec2(const float& x, const float& y);
	vec2 operator +(const vec2& other);
	vec2 operator -(const vec2& other);
	vec2 operator *(const vec2& other);
	vec2 operator /(const vec2& other);
	vec2& operator +=(const vec2& other);
	vec2& operator -=(const vec2& other);
	vec2& operator *=(const vec2& other);
	vec2& operator /=(const vec2& other);
	bool operator ==(const vec2& other);
	bool operator !=(const vec2& other);
public:
	float m_x;
	float m_y;
};
