#include "vec2.h"

vec2::vec2()
	:
	m_x(0.0f),
	m_y(0.0f)
{
	
}

vec2::vec2(const float& x, const float& y)
	:
	m_x(x),
	m_y(y)
{

}

vec2 vec2::operator +(const vec2& other)
{
	vec2 temp;
	temp.m_x = m_x + other.m_x;
	temp.m_y = m_y + other.m_y;
	return temp;
}

vec2 vec2::operator -(const vec2& other)
{
	vec2 temp;
	temp.m_x = m_x - other.m_x;
	temp.m_y = m_y - other.m_y;
	return temp;
}

vec2 vec2::operator *(const vec2& other)
{
	vec2 temp;
	temp.m_x = m_x * other.m_x;
	temp.m_y = m_y * other.m_y;
	return temp;
}

vec2 vec2::operator /(const vec2& other)
{
	vec2 temp;
	temp.m_x = m_x / other.m_x;
	temp.m_y = m_y / other.m_y;
	return temp;
}

vec2& vec2::operator +=(const vec2& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

vec2& vec2::operator -=(const vec2& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	return *this;
}

vec2& vec2::operator *=(const vec2& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
	return *this;
}
vec2& vec2::operator /=(const vec2& other)
{
	m_x /= other.m_x;
	m_y /= other.m_y;
	return *this;
}

bool vec2::operator ==(const vec2& other)
{
	return (this->m_x == other.m_x && this->m_y == other.m_y);
}

bool vec2::operator !=(const vec2& other)
{
	return !(*this == other);
}
