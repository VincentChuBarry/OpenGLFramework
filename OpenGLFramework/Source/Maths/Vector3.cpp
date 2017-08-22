#include "Vector3.h"

Vector3::Vector3()
	:
	m_x(0.0f),
	m_y(0.0f),
	m_z(0.0f)
{

}

Vector3::Vector3(const float& x, const float& y, const float& z)
	:
	m_x(x),
	m_y(y),
	m_z(z)
{

}

Vector3 Vector3::operator +(const Vector3& other)
{
	Vector3 temp;
	temp.m_x = m_x + other.m_x;
	temp.m_y = m_y + other.m_y;
	temp.m_z = m_z + other.m_z;
	return temp;
}

Vector3 Vector3::operator -(const Vector3& other)
{
	Vector3 temp;
	temp.m_x = m_x - other.m_x;
	temp.m_y = m_y - other.m_y;
	temp.m_z = m_z - other.m_z;
	return temp;
}

Vector3 Vector3::operator *(const Vector3& other)
{
	Vector3 temp;
	temp.m_x = m_x * other.m_x;
	temp.m_y = m_y * other.m_y;
	temp.m_z = m_z * other.m_z;
	return temp;
}

Vector3 Vector3::operator /(const Vector3& other)
{
	Vector3 temp;
	temp.m_x = m_x / other.m_x;
	temp.m_y = m_y / other.m_y;
	temp.m_z = m_z / other.m_z;
	return temp;
}

Vector3& Vector3::operator +=(const Vector3& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	return *this;
}

Vector3& Vector3::operator -=(const Vector3& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	return *this;
}

Vector3& Vector3::operator *=(const Vector3& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
	m_z *= other.m_z;
	return *this;
}
Vector3& Vector3::operator /=(const Vector3& other)
{
	m_x /= other.m_x;
	m_y /= other.m_y;
	m_z /= other.m_z;
	return *this;
}

bool Vector3::operator ==(const Vector3& other)
{
	return (this->m_x == other.m_x && this->m_y == other.m_y && this->m_z == other.m_z);
}

bool Vector3::operator !=(const Vector3& other)
{
	return !(*this == other);
}
