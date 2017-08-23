#include "Source\Graphics\Window.h"
#include "Source\Maths\Maths.h"
#include "Source\Graphics\Shader.h"
#include "Source\Graphics\Buffers\Buffer.h"
#include "Source\Graphics\Buffers\IndexBuffer.h"
#include "Source\Graphics\Buffers\VertexArray.h"

int main()
{

	Window m_window("OpenGLFramework", 960, 540);
	//glClearColor(1.0f, 1.3f, 1.8f, 1.0f);



	/*GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);*/

	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat coloursA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
	};
	GLfloat coloursB[] =
	{
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};
	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(coloursA, 4 * 4, 4), 1);

	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(coloursB, 4 * 4, 4), 1);


	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));
	
	shader.SetUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.SetUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	while (!m_window.Closed())
	{
		m_window.Clear();
		double x, y;
		m_window.GetMousePosition(x, y);
		shader.SetUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		//glDrawArrays(GL_TRIANGLES, 0, 6);

		sprite1.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Unbind();
		sprite1.Unbind();

		sprite2.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Unbind();
		sprite2.Unbind();

		m_window.Update();
	}
	return 0;
}