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

	scanf("%d %d %d", &n, &m, &k);

  for(int i = 0; i < n; i++){
    cin >> cities[i];
  }

  int l = 0;

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(i != j){
        if(strncmp(cities[i],cities[j],m) == 0){
          edges[l++] = {i, j, 1};
          // neighbours[i].push_back(pair<int, int>(j, 1));
          // neighbours[j].push_back(pair<int, int>(i, 1));
        }else{
          int counter = m;
          for(int h = k ; h >= k-m; h--){
            if(cities[i][h] != cities[j][h]) counter++;
          }
          edges[l++] = {i, j, counter};
          // neighbours[i].push_back(pair<int, int>(j, counter));
          // neighbours[j].push_back(pair<int, int>(i, counter));
        }
      }
    }
  }
	cout << kruskal() << endl;

	return 0;
}

