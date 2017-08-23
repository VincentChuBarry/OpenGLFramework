#pragma once
#pragma once
#include <iostream>

class vec3
{
public:
	vec3();
	vec3(const float& x, const float& y, const float& z);
	vec3 operator +(const vec3& other);
	vec3 operator -(const vec3& other);
	vec3 operator *(const vec3& other);
	vec3 operator /(const vec3& other);
	vec3& operator +=(const vec3& other);
	vec3& operator -=(const vec3& other);
	vec3& operator *=(const vec3& other);
	vec3& operator /=(const vec3& other);
	bool operator ==(const vec3& other);
	bool operator !=(const vec3& other);
public:
	float m_x;
	float m_y;
	float m_z;
};
