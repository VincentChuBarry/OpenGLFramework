#pragma once
#include <iostream>
#include <glew.h>
#include <glfw3.h>

#define MAX_KEYS 1024
#define MAX_MOUSEBUTTONS 32

class Window
{
public:
	Window(const char* windowTitle, int width, int height);
	~Window();
	void Clear() const;
	void Update();
	bool Closed() const;
	bool IsKeyPressed(unsigned int keycode) const;
	bool IsMouseButtonPressed(unsigned int keycode) const;
	void GetMousePosition(double& posX, double& posY) const;
private:
	bool Initialise();
	friend void Window_Resize(GLFWwindow* window, int width, int height);
	friend void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void MouseButton_Callback(GLFWwindow* window, int key, int action, int mods);
	friend void CursorPosition_Callback(GLFWwindow* window, double posX, double posY);
private:
	const char* m_windowTitle;
	int m_width;
	int m_height;
	GLFWwindow* m_window;
	bool m_closed;
	bool m_keys[MAX_KEYS];
	bool m_mouseButtons[MAX_MOUSEBUTTONS];
	double m_mouseX;
	double m_mouseY;
};
