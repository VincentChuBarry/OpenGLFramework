#include "Source\Graphics\Window.h"
#include "Source\Maths\Maths.h"
#include "Source\Graphics\Shader.h"
#include "Source\Graphics\Buffers\Buffer.h"
#include "Source\Graphics\Buffers\IndexBuffer.h"
#include "Source\Graphics\Buffers\VertexArray.h"
#include "Source\Graphics\Simple2DRenderer.h"

int main()
{

	Window m_window("OpenGLFramework", 960, 540);
	//glClearColor(1.0f, 1.3f, 1.8f, 1.0f);

	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", mat4::Translation(vec3(4, 3, 0)));

	Renderable2D sprite(vec3(5, 5, 0), vec2(4, 4), vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(vec3(7, 1, 0), vec2(2, 3), vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;
	
	shader.SetUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.SetUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	while (!m_window.Closed())
	{
		m_window.Clear();
		double x, y;
		m_window.GetMousePosition(x, y);
		shader.SetUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.Submit(&sprite);
		renderer.Submit(&sprite2);
		renderer.Flush();

		m_window.Update();
	}
	return 0;
}