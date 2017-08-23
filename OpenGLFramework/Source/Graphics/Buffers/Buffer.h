#pragma once
#include "..\..\..\..\Dependencies\GLEW\Include\GL\glew.h"

class Buffer
{
public:
	Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
	void Bind() const;
	void Unbind() const;
	inline GLuint GetComponentCount() const
	{
		return m_componentCount;
	}
private:
	GLuint m_bufferID;
	GLuint m_componentCount;
};
