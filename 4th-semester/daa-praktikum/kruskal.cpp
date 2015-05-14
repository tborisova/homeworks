/* Minimum spanning tree - Kruskal
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10001
#define M 100000

struct edge
{
	int x, y, weight;
	bool operator < (const edge &other) const {
		return weight < other.weight;
	}
} edges[M];

int parent[N];
int n, m;

int getRoot(int v)
{
	int root = v;
	while (parent[root] != -1)
		root = parent[root];

	// Optimization: Path compression
	// Set root as the parent of each vertex on the path from v to root
	int temp;
	while (v != root)
	{
		temp = parent[v];
		parent[v] = root;
		v = temp;
	}

	return root;
}

long long kruskal()
{
	sort(edges, edges + m);

	// ! If vertices are from 1 to n
	for (int i = 1; i <= n; i++)
		parent[i] = -1;

	int edgeCount = 0, rootX, rootY;
	long long edgeSum = 0;

	for (int i = 0; i < m && edgeCount < n - 1; i++)
	{
		rootX = getRoot(edges[i].x);
		rootY = getRoot(edges[i].y);
		if (rootX != rootY)
		{
			edgeSum += edges[i].weight;
			edgeCount++;
			parent[rootY] = rootX;
		}
	}

	return edgeSum;
}

int main()
{
	int x, y, weight;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> weight;
		edges[i] = { x, y, weight };
	}

	cout << kruskal() << endl;

	return 0;
}

