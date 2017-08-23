#include "Source\Graphics\Window.h"
#include "Source\Maths\Maths.h"
#include "Source\Graphics\Shader.h"

int main()
{

	Window m_window("OpenGLFramework", 960, 540);
	glClearColor(1.0f, 1.3f, 1.8f, 1.0f);

	GLfloat vertices[] =
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
	glEnableVertexAttribArray(0);

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

		glDrawArrays(GL_TRIANGLES, 0, 6);
		m_window.Update();
	}
	return 0;
}