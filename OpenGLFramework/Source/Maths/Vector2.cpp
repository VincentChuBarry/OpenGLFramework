#include "Vector2.h"

Vector2::Vector2()
	:
	m_x(0.0f),
	m_y(0.0f)
{
	
}

Vector2::Vector2(const float& x, const float& y)
	:
	m_x(x),
	m_y(y)
{

}

Vector2 Vector2::operator +(const Vector2& other)
{
	Vector2 temp;
	temp.m_x = m_x + other.m_x;
	temp.m_y = m_y + other.m_y;
	return temp;
}

Vector2 Vector2::operator -(const Vector2& other)
{
	Vector2 temp;
	temp.m_x = m_x - other.m_x;
	temp.m_y = m_y - other.m_y;
	return temp;
}

Vector2 Vector2::operator *(const Vector2& other)
{
	Vector2 temp;
	temp.m_x = m_x * other.m_x;
	temp.m_y = m_y * other.m_y;
	return temp;
}

Vector2 Vector2::operator /(const Vector2& other)
{
	Vector2 temp;
	temp.m_x = m_x / other.m_x;
	temp.m_y = m_y / other.m_y;
	return temp;
}

Vector2& Vector2::operator +=(const Vector2& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Vector2& Vector2::operator -=(const Vector2& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	return *this;
}

Vector2& Vector2::operator *=(const Vector2& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
	return *this;
}
Vector2& Vector2::operator /=(const Vector2& other)
{
	m_x /= other.m_x;
	m_y /= other.m_y;
	return *this;
}

bool Vector2::operator ==(const Vector2& other)
{
	return (this->m_x == other.m_x && this->m_y == other.m_y);
}

bool Vector2::operator !=(const Vector2& other)
{
	return !(*this == other);
}
