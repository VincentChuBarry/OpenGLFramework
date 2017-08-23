#pragma once
#include "..\..\..\..\Dependencies\GLEW\Include\GL\glew.h"

class IndexBuffer
{
public:
	IndexBuffer(GLushort* data, GLsizei count);
	void Bind() const;
	void Unbind() const;
	inline GLuint GetCount() const
	{
		return m_count;
	}
private:
	GLuint m_bufferID;
	GLuint m_count;
};
