#include "Simple2DRenderer.h"

void Simple2DRenderer::Submit(const Renderable2D* renderable)
{
	m_renderQueue.push_back(renderable);
}

void Simple2DRenderer::Flush()
{
	while (!m_renderQueue.empty())
	{
		const Renderable2D* renderable = m_renderQueue.front();
		renderable->GetVAO()->Bind();
		renderable->GetIBO()->Bind();

		renderable->GetShader().SetUniformMat4("ml_matrix", mat4::Translation(renderable->GetPosition()));
		glDrawElements(GL_TRIANGLES, renderable->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

		renderable->GetVAO()->Unbind();
		renderable->GetIBO()->Unbind();

		m_renderQueue.pop_front();
	}
}