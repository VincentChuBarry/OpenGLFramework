#include "Vector4.h"

Vector4::Vector4()
	:
	m_x(0.0f),
	m_y(0.0f),
	m_z(0.0f),
	m_w(0.0f)
{

}

Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
	:
	m_x(x),
	m_y(y),
	m_z(z),
	m_w(w)
{

}

Vector4 Vector4::operator +(const Vector4& other)
{
	Vector4 temp;
	temp.m_x = m_x + other.m_x;
	temp.m_y = m_y + other.m_y;
	temp.m_z = m_z + other.m_z;
	temp.m_w = m_w + other.m_w;
	return temp;
}

Vector4 Vector4::operator -(const Vector4& other)
{
	Vector4 temp;
	temp.m_x = m_x - other.m_x;
	temp.m_y = m_y - other.m_y;
	temp.m_z = m_z - other.m_z;
	temp.m_w = m_w - other.m_w;
	return temp;
}

Vector4 Vector4::operator *(const Vector4& other)
{
	Vector4 temp;
	temp.m_x = m_x * other.m_x;
	temp.m_y = m_y * other.m_y;
	temp.m_z = m_z * other.m_z;
	temp.m_w = m_w * other.m_w;
	return temp;
}

Vector4 Vector4::operator /(const Vector4& other)
{
	Vector4 temp;
	temp.m_x = m_x / other.m_x;
	temp.m_y = m_y / other.m_y;
	temp.m_z = m_z / other.m_z;
	temp.m_w = m_w / other.m_w;
	return temp;
}

Vector4& Vector4::operator +=(const Vector4& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	m_w += other.m_w;
	return *this;
}

Vector4& Vector4::operator -=(const Vector4& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	m_w -= other.m_w;
	return *this;
}

Vector4& Vector4::operator *=(const Vector4& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
	m_z *= other.m_z;
	m_w *= other.m_w;
	return *this;
}
Vector4& Vector4::operator /=(const Vector4& other)
{
	m_x /= other.m_x;
	m_y /= other.m_y;
	m_z /= other.m_z;
	m_w /= other.m_w;
	return *this;
}

bool Vector4::operator ==(const Vector4& other)
{
	return (this->m_x == other.m_x && this->m_y == other.m_y 
		&& this->m_z == other.m_z && this->m_w == other.m_w);
}

bool Vector4::operator !=(const Vector4& other)
{
	return !(*this == other);
}
