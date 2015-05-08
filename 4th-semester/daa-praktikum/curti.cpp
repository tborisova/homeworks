/* Prim
*/
#include<cstdio>
#include<vector>
#include<queue>
#include <iostream>
#include <functional>
#include <climits>

using namespace std;

#define INF INT_MAX
#define N 1001

int a[N][N];
int n, m;
vector<pair<int, int> > neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };

// Find the MST with root vertex s
int prim(int s)
{
  // By default, priority queue uses less comparator (max heap).
  // We need min heap => greater
  // By default, pairs are sorted by first coordinate, then by second.
  // => (dist[v], v)
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  // ! If vertex indexes are from {1, .. n}
  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));
  int verticesCount = 0;
  int maxEdge = 0;

  while (!pq.empty())
  {
    int current = pq.top().second;
    pq.pop();
    if (visited[current]) // We push multiple pairs with the same vertex, but different distances. 
      continue;      // This vertex has already been popped (with shorter distance).

    // Important: mark vertices as visited after popping, not before pushing.
    // We continue updating the best distance for pushed vertices.
    visited[current] = 1;
    verticesCount++;
    if(maxEdge < dist[current]) maxEdge = dist[current];
    if (verticesCount == n)
      break;

    for (int i = 0; i < neighbours[current].size(); i++)
    {
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if (!visited[next])
      {
        if (dist[next] > edge)
        {
          dist[next] = edge;
          pq.push(pair<int, int>(dist[next], next));
        }
      }
    }

  }
  return maxEdge;
}

int main()
{
  scanf("%d%d", &n, &m);
  int v1, v2, weight;

  for(int i = 1; i <=n;i++)
    for(int j = 1; j <=n;j++)
      a[i][j] = 0;

  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &v1, &v2, &weight);
    a[v1][v2] = max(a[v1][v2], weight);
    a[v1][v2] = max(a[v1][v2], a[v2][v1]);
    a[v2][v1] = a[v1][v2];
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <=n; j++){
      if(a[i][j]){
        neighbours[i].push_back(pair<int, int>(j, a[i][j]));
        neighbours[j].push_back(pair<int, int>(i, a[i][j]));
      }
    }
  }
  // Choose a random vertex as root
  printf("%d\n", prim(1));

  return 0;
}