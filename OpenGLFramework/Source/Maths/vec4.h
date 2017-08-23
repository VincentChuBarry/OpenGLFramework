#pragma once
#pragma once
#include <iostream>

class vec4
{
public:
	vec4();
	vec4(const float& x, const float& y, const float& z, const float& w);
	vec4 operator +(const vec4& other);
	vec4 operator -(const vec4& other);
	vec4 operator *(const vec4& other);
	vec4 operator /(const vec4& other);
	vec4& operator +=(const vec4& other);
	vec4& operator -=(const vec4& other);
	vec4& operator *=(const vec4& other);
	vec4& operator /=(const vec4& other);
	bool operator ==(const vec4& other);
	bool operator !=(const vec4& other);
public:
	float m_x;
	float m_y;
	float m_z;
	float m_w;
};
