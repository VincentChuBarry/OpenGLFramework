#pragma once
#include "Maths.h"

class mat4
{
public:
	union
	{
		float m_elements[4 * 4];
		vec4 m_columns[4];
	};
	mat4();
	mat4(float diagonal);
	vec4 GetColumn(int index)
	{
		index *= 4;
		return vec4(m_elements[index], m_elements[index + 1], m_elements[index + 2], m_elements[index + 3]);
	}
	static mat4 Identity();

	mat4& Multiply(const mat4& other);
	friend mat4 operator*(mat4 left, const mat4& right);
	mat4& operator*=(const mat4& other);

	static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
	static mat4 Perspective(float fov, float aspectRatio, float near, float far);

	static mat4 Translation(const vec3& translation);
	static mat4 Rotation(float angle, const vec3& axis);
	static mat4 Scale(const vec3& scale);
};

