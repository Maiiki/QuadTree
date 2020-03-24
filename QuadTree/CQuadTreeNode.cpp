#include "CQuadTreeNode.h"



template<class T>
inline CQuadTreeNode<T>::CQuadTreeNode()
	:m_n1(nullptr), m_n2(nullptr), m_n3(nullptr), m_n4(nullptr)
{
}

template<class T>
CQuadTreeNode<T>::~CQuadTreeNode()
{
	if (m_n1 != nullptr) { delete m_n1; m_n1 = nullptr; }
	if (m_n2 != nullptr) { delete m_n2; m_n2 = nullptr; }
	if (m_n3 != nullptr) { delete m_n3; m_n3 = nullptr; }
	if (m_n4 != nullptr) { delete m_n4; m_n4 = nullptr; }
}

template<class T>
bool CQuadTreeNode<T>::isVertexInsideBounds(CVector2D vertex)
{
	if ((vertex.getX() > m_bounds.m_topLeft.X)
		&& (vertex.getX() < m_bounds.m_topRight.X)
		&& (vertex.getY() > m_bounds.m_topLeft.Y)
		&& (vertex.getY() < m_bounds.m_botRight.Y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void CQuadTreeNode<T>::subdivide(int limit, vector<CVector2D>* all_vertices)
{
}

