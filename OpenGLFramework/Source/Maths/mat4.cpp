#include "mat4.h"

mat4::mat4()
{
	for (int i = 0; i < 4 * 4; i++)
	{
		m_elements[i] = 0.0f;
	}
}

mat4::mat4(float diagonal)
{
	for (int i = 0; i < 4 * 4; i++)
	{
		m_elements[i] = 0.0f;
	}
	m_elements[0 + 0 * 4] = diagonal;
	m_elements[1 + 1 * 4] = diagonal;
	m_elements[2 + 2 * 4] = diagonal;
	m_elements[3 + 3 * 4] = diagonal;
}

mat4 mat4::Identity()
{
	return mat4(1.0f);
}

mat4& mat4::Multiply(const mat4& other)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			float sum = 0.0f;
			for (int e = 0; e < 4; e++)
			{
				sum += m_elements[x + e * 4] * other.m_elements[e + y * 4];
			}
			m_elements[x + y * 4] = sum;
		}
	}

	return *this;
}

mat4 operator*(mat4 left, const mat4& right)
{
	return left.Multiply(right);
}

mat4& mat4::operator*=(const mat4& other)
{
	return Multiply(other);
}

mat4 mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
{
	mat4 result(1.0f);

	result.m_elements[0 + 0 * 4] = 2.0f / (right - left);
	result.m_elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.m_elements[2 + 2 * 4] = 2.0f / (near - far);

	result.m_elements[0 + 3 * 4] = (left + right) / (left - right);
	result.m_elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
	result.m_elements[2 + 3 * 4] = (far + near) / (far - near);

	return result;
}

mat4 mat4::Perspective(float fov, float aspectRatio, float near, float far)
{
	mat4 result(1.0f);

	float q = 1.0f / tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;

	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);

	result.m_elements[0 + 0 * 4] = a;
	result.m_elements[1 + 1 * 4] = q;
	result.m_elements[2 + 2 * 4] = b;
	result.m_elements[3 + 2 * 4] = -1.0f;
	result.m_elements[2 + 3 * 4] = c;

	return c;
}

mat4 mat4::Translation(const vec3& translation)
{
	mat4 result(1.0f);

	result.m_elements[0 + 3 * 4] = translation.m_x;
	result.m_elements[1 + 3 * 4] = translation.m_y;
	result.m_elements[2 + 3 * 4] = translation.m_z;

	return result;
}

mat4 mat4::Rotation(float angle, const vec3& axis)
{
	mat4 result(1.0f);

	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	float x = axis.m_x;
	float y = axis.m_y;
	float z = axis.m_z;

	result.m_elements[0 + 0 * 4] = x * omc + c;
	result.m_elements[1 + 0 * 4] = y * x * omc + z * s;
	result.m_elements[2 + 0 * 4] = x * z * omc - y * s;

	result.m_elements[0 + 1 * 4] = x * y * omc - z * s;
	result.m_elements[1 + 1 * 4] = y * omc + c;
	result.m_elements[2 + 1 * 4] = y * z * omc + x * s;

	result.m_elements[0 + 2 * 4] = x * z * omc + y * s;
	result.m_elements[1 + 2 * 4] = y * z * omc - x * s;
	result.m_elements[2 + 2 * 4] = z * omc + c;

	return result;
}

mat4 mat4::Scale(const vec3& scale)
{
	mat4 result(1.0f);

	result.m_elements[0 + 0 * 4] = scale.m_x;
	result.m_elements[1 + 1 * 4] = scale.m_y;
	result.m_elements[2 + 2 * 4] = scale.m_z;

	return result;
}

