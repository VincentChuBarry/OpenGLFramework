#pragma once
#include "..\Maths\Maths.h"
#include "Buffers\Buffer.h"
#include "Buffers\IndexBuffer.h"
#include "Buffers\VertexArray.h"
#include "Shader.h"

class Renderable2D
{
public:
	Renderable2D(vec3 position, vec2 size, vec4 colour, Shader& shader)
		:
		m_position(position),
		m_size(size),
		m_colour(colour),
		m_shader(shader)
	{
		m_vertexArray = new VertexArray();
		GLfloat vertices[] = 
		{
			0, 0, 0,
			0, size.m_y, 0,
			size.m_x, size.m_y, 0,
			size.m_x, 0, 0
		};
		GLfloat colours[] =
		{
			colour.m_x, colour.m_y, colour.m_z, colour.m_w,
			colour.m_x, colour.m_y, colour.m_z, colour.m_w,
			colour.m_x, colour.m_y, colour.m_z, colour.m_w,
			colour.m_x, colour.m_y, colour.m_z, colour.m_w
		};
		m_vertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_vertexArray->AddBuffer(new Buffer(colours, 4 * 4, 4), 1);
		GLushort indices[] =
		{
			0, 1, 2,
			2, 3, 0
		};
		m_indexBuffer = new IndexBuffer(indices, 6);
	}

	virtual ~Renderable2D()
	{
		delete m_vertexArray;
		delete m_indexBuffer;
	}
	inline const VertexArray* GetVAO() const
	{
		return m_vertexArray;
	}
	inline const IndexBuffer* GetIBO() const
	{
		return m_indexBuffer;
	}
	inline Shader& GetShader() const
	{
		return m_shader;
	}
	inline const vec3& GetPosition() const
	{
		return m_position;
	}
	inline const vec2& GetSize() const
	{
		return m_size;
	}
	inline const vec4& GetColour() const
	{
		return m_colour;
	}
protected:
	vec3 m_position;
	vec2 m_size;
	vec4 m_colour;
	VertexArray* m_vertexArray;
	IndexBuffer* m_indexBuffer;
	Shader& m_shader;
};
