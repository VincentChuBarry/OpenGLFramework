#pragma once
#pragma once
#include <iostream>

class Vector4
{
public:
	Vector4();
	Vector4(const float& x, const float& y, const float& z, const float& w);
	Vector4 operator +(const Vector4& other);
	Vector4 operator -(const Vector4& other);
	Vector4 operator *(const Vector4& other);
	Vector4 operator /(const Vector4& other);
	Vector4& operator +=(const Vector4& other);
	Vector4& operator -=(const Vector4& other);
	Vector4& operator *=(const Vector4& other);
	Vector4& operator /=(const Vector4& other);
	bool operator ==(const Vector4& other);
	bool operator !=(const Vector4& other);
public:
	float m_x;
	float m_y;
	float m_z;
	float m_w;
};
