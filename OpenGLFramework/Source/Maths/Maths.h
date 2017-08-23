#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"


inline float ToRadians(float degrees)
{
	return degrees * (float)(M_PI / 180.0f);
}