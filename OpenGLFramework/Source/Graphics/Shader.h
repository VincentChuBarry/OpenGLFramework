#pragma once
#include <iostream>
#include <vector>
#include <glew.h>
#include "../Maths/mat4.h"

class Shader
{
public:
	Shader(const char* vertPath, const char* fragPath);
	~Shader();
	void SetUniform1f(const GLchar* name, float value);
	void SetUniform1i(const GLchar* name, int value);
	void SetUniform2f(const GLchar* name, const vec2& vector);
	void SetUniform3f(const GLchar* name, const vec3& vector);
	void SetUniform4f(const GLchar* name, const vec4& vector);
	void SetUniformMat4(const GLchar* name, const mat4& matrix);
	void Enable() const;
	void Disable() const;
private:
	GLuint Load();
	GLint GetUniformLocation(const GLchar* name);
private:
	GLuint m_shaderID;
	const char* m_vertexPath;
	const char* m_fragmentPath;
};