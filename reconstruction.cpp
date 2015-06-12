/* Prim
*/
#include<cstdio>
#include<vector>
#include<queue>
#include <iostream>
#include <functional>
#include <climits>
#include <map>
#include <cmath>

using namespace std;

#define INF INT_MAX
#define N 50001

int n, m, k;
vector<pair<int, int> > neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };
int parent[N];

// Find the MST with root vertex s
long long prim(int s)
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
    parent[i] = -1;
  }
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));
  int verticesCount = 0;
  long long edgeSum = 0;

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
    edgeSum += dist[current];
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
          parent[next] = current;
          pq.push(pair<int, int>(dist[next], next));
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
  int k;
  scanf("%d %d %d", &n, &m, &k);
  int  weight;
  map<char*, int> cities;
  int counter = 1;
  char v1[11], v2[11];

  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2;

    if(cities[v1] != 0){
      cities[v1] = counter;
    }

    if(cities[v2] != 0){
      cities[v2] = counter + 1;
    }

    counter++;
    // Multiple edges from v1 to v2 are not a problem - all will be considered
    neighbours[cities[v1]].push_back(pair<int, int>(cities[v2], weight));
    neighbours[cities[v2]].push_back(pair<int, int>(cities[v1], weight));  // If undirected graph
  }

  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> weight;

    if(cities[v1] != 0){
      cities[v1] = counter;
    }

    if(cities[v2] != 0){
      cities[v2] = counter + 1;
    }

    counter++;
    // Multiple edges from v1 to v2 are not a problem - all will be considered
    neighbours[cities[v1]].push_back(pair<int, int>(cities[v2], weight));
    neighbours[cities[v2]].push_back(pair<int, int>(cities[v1], weight));  // If undirected graph
  }

  // Choose a random vertex as root
  printf("%lld\n", prim(1));

  return 0;
}