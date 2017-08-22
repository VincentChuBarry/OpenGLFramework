#pragma once
#pragma once
#include <iostream>

class Vector3
{
public:
	Vector3();
	Vector3(const float& x, const float& y, const float& z);
	Vector3 operator +(const Vector3& other);
	Vector3 operator -(const Vector3& other);
	Vector3 operator *(const Vector3& other);
	Vector3 operator /(const Vector3& other);
	Vector3& operator +=(const Vector3& other);
	Vector3& operator -=(const Vector3& other);
	Vector3& operator *=(const Vector3& other);
	Vector3& operator /=(const Vector3& other);
	bool operator ==(const Vector3& other);
	bool operator !=(const Vector3& other);
public:
	float m_x;
	float m_y;
	float m_z;
};
