#include "shader.h"
#include "../Utilities/FileReader.h"

Shader::Shader(const char* vertPath, const char* fragPath)
	: 
	m_vertexPath(vertPath),
	m_fragmentPath(fragPath)
{
	m_shaderID = Load();
}

Shader::~Shader()
{
	glDeleteProgram(m_shaderID);
}

GLuint Shader::Load()
{
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexSourceString = FileReader::ReadFile(m_vertexPath);
	std::string fragmentSourceString = FileReader::ReadFile(m_fragmentPath);

	const char* vertSource = vertexSourceString.c_str();
	const char* fragSource = fragmentSourceString.c_str();

	glShaderSource(vertex, 1, &vertSource, NULL);
	glCompileShader(vertex);

	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertex, length, &length, &error[0]);
		std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
		glDeleteShader(vertex);
		return 0;
	}

	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(fragment, length, &length, &error[0]);
		std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
		glDeleteShader(fragment);
		return 0;
	}

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

GLint Shader::GetUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(m_shaderID, name);
}

void Shader::SetUniform1f(const GLchar* name, float value)
{
	glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform1i(const GLchar* name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform2f(const GLchar* name, const vec2& vector)
{
	glUniform2f(GetUniformLocation(name), vector.m_x, vector.m_y);
}

void Shader::SetUniform3f(const GLchar* name, const vec3& vector)
{
	glUniform3f(GetUniformLocation(name), vector.m_x, vector.m_y, vector.m_z);
}

void Shader::SetUniform4f(const GLchar* name, const vec4& vector)
{
	glUniform4f(GetUniformLocation(name), vector.m_x, vector.m_y, vector.m_z, vector.m_w);
}

void Shader::SetUniformMat4(const GLchar* name, const mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.m_elements);
}

void Shader::Enable() const
{
	glUseProgram(m_shaderID);
}

void Shader::Disable() const
{
	glUseProgram(0);
}