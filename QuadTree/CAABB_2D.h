#pragma once
#include "CVector2D.h"

class CAABB_2D
{
private:
	CVector2D m_topLeft, m_topRight, m_botLeft, m_botRight;

public:
	CAABB_2D(float minX, float maxX, float minY, float maxY);
	CAABB_2D();
	~CAABB_2D();
};

