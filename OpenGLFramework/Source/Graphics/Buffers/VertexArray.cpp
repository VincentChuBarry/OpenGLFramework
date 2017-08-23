#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_arrayID);
}

VertexArray::~VertexArray()
{
	for (int i = 0; i < m_buffers.size(); i++)
	{
		delete m_buffers[i];
	}
}

void VertexArray::AddBuffer(Buffer* buffer, GLuint index)
{
	Bind();

	buffer->Bind();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->Unbind();
	Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_arrayID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}