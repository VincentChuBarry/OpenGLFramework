#include "Source\Graphics\Window.h"
#include "Source\Maths\Maths.h"

int main()
{

	Window m_window("OpenGLFramework", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vector4 vec1(105.0f, 20.0f, 5.0f, 15.0f);
	Vector4 vec2(10.0f, 20.0f, 25.0f, 35.0f);
	Vector4 vec4 = vec1 + vec2;
	while (!m_window.Closed())
	{
		m_window.Clear();
		double x, y;
		m_window.GetMousePosition(x, y);
		std::cout << "x: " << vec1.m_x << "y: " << vec1.m_y << std::endl;
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		m_window.Update();
	}
	return 0;
}