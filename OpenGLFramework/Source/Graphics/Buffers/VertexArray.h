#pragma once
#include "Buffer.h"
#include <vector>

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void AddBuffer(Buffer* buffer, GLuint index);
	void Bind() const;
	void Unbind() const;
private:
	GLuint m_arrayID;
	std::vector<Buffer*> m_buffers;
};