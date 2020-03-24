#pragma once
#include "CQuadTreeNode.h"

template<class T>
class CQuadTree
{
private:
	CQuadTreeNode<T>* m_root;

public:
	CQuadTree();
	void subdivide(int limit, vector<CVector2D>* all_vertices);
	void render();
};

