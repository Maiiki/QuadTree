#include"CQuadTree.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	vector<CVector2D> all_vertices;

	for (size_t i = 0; i < 100; i++)
	{
		CVector2D vertex;
		vertex.X = rand() % 100;
		vertex.Y = rand() % 100;
		all_vertices.push_back(vertex);
	}

	for (size_t i = 0; i < all_vertices.size(); i++)
	{
		cout << i << ":\t" << all_vertices[i] << endl;
	}

	return 0;
}