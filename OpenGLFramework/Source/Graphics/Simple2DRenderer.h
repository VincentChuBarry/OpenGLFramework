#pragma once
#include "Renderer2D.h"
#include <deque>

class Simple2DRenderer : public Renderer2D
{
private:
	std::deque<const Renderable2D*> m_renderQueue;
public:
	void Submit(const Renderable2D* renderable) override;
	void Flush() override;
};