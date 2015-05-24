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
#define N 50001


struct island {
    int vertex, cost, capacity;
    
    // island(int _vertex, int _cost, int _capacity) {
    //     vertex = _vertex;
    //     cost = _cost;
    //     capacity = _capacity;
    // }

    island(int _vertex=0, int _cost=0, int _capacity=0) {
        vertex = _vertex;
        cost = _cost;
        capacity = _capacity;
    }

    bool operator<(const island& other) const{
      return true;
    }
};

int n, m;
vector<island> neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };
int parent[N];
int min_capacity = INT_MAX;

// Find the MST with root vertex s
int prim(island s)
{
  // By default, priority queue uses less comparator (max heap).
  // We need min heap => greater
  // By default, pairs are sorted by first coordinate, then by second.
  // => (dist[v], v)
  priority_queue<pair<int, island>, vector<pair<int, island> >, greater<pair<int, island> > > pq;

  // ! If vertex indexes are from {1, .. n}
  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
    parent[i] = -1;
  }
  dist[s.vertex] = 0;
  pq.push(pair<int, island>(0, s));
  int verticesCount = 0;
  long long edgeSum = 0;

  while (!pq.empty())
  {
    island current = pq.top().second;
    pq.pop();
    if (visited[current.vertex]) // We push multiple pairs with the same vertex, but different distances. 
      continue;      // This vertex has already been popped (with shorter distance).

    // Important: mark vertices as visited after popping, not before pushing.
    // We continue updating the best distance for pushed vertices.
    visited[current.vertex] = 1;
    verticesCount++;
    edgeSum += dist[current.vertex];
    if(min_capacity > current.capacity) min_capacity = current.capacity;
    if (verticesCount == n)
      break;

    for (int i = 0; i < neighbours[current.vertex].size(); i++)
    {
      int next = neighbours[current.vertex][i].vertex;
      int edge = neighbours[current.vertex][i].cost;
      if (!visited[next])
      {
        if (dist[next] > edge)
        {
          parent[next] = current.vertex;
          dist[next] = edge;
          pq.push(pair<int, island>(dist[next], neighbours[current.vertex][i]));
        }
      }
    }

  }
  if (verticesCount < n)  // The graph is not connected
    return -1;
  return edgeSum;
}


int main()
{
  scanf("%d %d", &n, &m);
  int v1, v2, cost, capacity;
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d %d %d", &v1, &v2, &cost, &capacity);
    // Multiple edges from v1 to v2 are not a problem - all will be considered
    neighbours[v1].push_back(island(v2, cost, capacity));
    neighbours[v2].push_back(island(v1, cost, capacity));  // If undirected graph
  }

  prim(island(1, 0, INT_MAX));
  cout << min_capacity - 1 << endl;
  return 0;
}