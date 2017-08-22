#include "Window.h"

Window::Window(const char* windowTitle, int width, int height)
	:
	m_windowTitle(windowTitle),
	m_width(width),
	m_height(height)
{
	if (!Initialise())
	{
		glfwTerminate();
	}
	for (int i = 0; i < MAX_KEYS; i++)
	{
		m_keys[i] = false;
	}
	for (int i = 0; i < MAX_MOUSEBUTTONS; i++)
	{
		m_mouseButtons[i] = false;
	}
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::Initialise()
{
	if (!glfwInit())
	{
		std::cout << "Failed to Initialise GLFW" << std::endl;
		return false;
	}
	m_window = glfwCreateWindow(m_width, m_height, m_windowTitle, NULL, NULL);
	if (!m_window)
	{
		std::cout << "Failed to create window" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetWindowSizeCallback(m_window, Window_Resize);
	glfwSetKeyCallback(m_window, Key_Callback);
	glfwSetMouseButtonCallback(m_window, MouseButton_Callback);
	glfwSetCursorPosCallback(m_window, CursorPosition_Callback);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialise GELW" << std::endl;
		return false;
	}
	return true;

	std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;
}

void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

bool Window::Closed() const
{
	return glfwWindowShouldClose(m_window) == 1;
}

bool Window::IsKeyPressed(unsigned int keycode) const
{
	if (keycode >= MAX_KEYS)
	{
		return false;
	}
	return m_keys[keycode];
}

bool Window::IsMouseButtonPressed(unsigned int button) const
{
	if (button >= MAX_MOUSEBUTTONS)
	{
		return false;
	}
	return m_mouseButtons[button];
}

void Window::GetMousePosition(double& posX, double& posY) const
{
	posX = m_mouseX;
	posY = m_mouseY;
}

void Window_Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_keys[key] = action != GLFW_RELEASE;
}

void MouseButton_Callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_mouseButtons[button] = action != GLFW_RELEASE;
}
void CursorPosition_Callback(GLFWwindow* window, double posX, double posY)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_mouseX = posX;
	win->m_mouseY = posY;
}
		
