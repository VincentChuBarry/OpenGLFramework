#pragma once
#include "Renderable2D.h"
#include "..\Maths\Maths.h"
#include "..\..\..\Dependencies\GLEW\Include\GL\glew.h"

class Renderer2D
{
public:
	virtual void Submit(const Renderable2D* renderable) = 0;
	virtual void Flush() = 0;
};