#include "Source\Graphics\Window.h"

int main()
{
	using namespace OpenGLFramework;
	using namespace Graphics;

	Window m_window("OpenGLFramework", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!m_window.Closed())
	{
		m_window.Clear();
		double x, y;
		m_window.GetMousePosition(x, y);
		std::cout << "x: " << x << "y: " << y << std::endl;
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