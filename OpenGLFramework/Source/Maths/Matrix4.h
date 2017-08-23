#pragma once
#include "Maths.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float diagonal);
	static Matrix4 Identity();
	Matrix4 operator *(const Matrix4& other);
	Matrix4 operator *=(const Matrix4& other);
	static Matrix4 Orthographic(float left, float right, float top, float bottom, float near, float far);
	static Matrix4 Perspective(float fov, float aspectRatio, float near, float far);
	static Matrix4 Translation(const Vector3& translation);
	static Matrix4 Rotation(float angle, const Vector3& axis);
	static Matrix4 Scale(const Vector3& scale);
	
public:
	float m_elements[4 * 4];
};
