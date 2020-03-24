#include "CAABB_2D.h"

CAABB_2D::CAABB_2D(float minX, float maxX, float minY, float maxY)
{
	m_topLeft.X = minX;
	m_topLeft.Y = maxY;
	m_topRight.X = maxX;
	m_topRight.Y = maxY;
	m_botLeft.X = minX;
	m_botLeft.Y = minY;
	m_botRight.X = maxX;
	m_botRight.Y = minY;
}

CAABB_2D::CAABB_2D()
{
}

CAABB_2D::~CAABB_2D()
{
}
