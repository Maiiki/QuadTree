#pragma once
#include"CAABB_2D.h"
#include<vector>
using namespace std;

template<class T>
class CQuadTreeNode
{
private:
	CQuadTreeNode<T>* m_n1, * m_n2, * m_n3, * m_n4;
	CAABB_2D m_bounds;

	bool isVertexInsideBounds(CVector2D vertex);

public:
	CQuadTreeNode();
	~CQuadTreeNode();

	inline void setBounds(CAABB_2D bounds) { m_bounds = bounds; }
	void subdivide(int limit, vector<CVector2D>* all_vertices);
};

