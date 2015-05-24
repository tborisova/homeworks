/* Prim
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <climits>
#include <cstring>
using namespace std;

#define INF INT_MAX
#define N 1001
#define K 51

int n, m, k;
vector<pair<int, int> > neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };
int parent[N];
char cities[N][K];

// Find the MST with root vertex s
int prim(int s)
{
  // By default, priority queue uses less comparator (max heap).
  // We need min heap => greater
  // By default, pairs are sorted by first coordinate, then by second.
  // => (dist[v], v)
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  // ! If vertex indexes are from {1, .. n}
  for (int i = 0; i < n; i++)
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
    cout << " " << current << " " << edgeSum << endl;
    if (visited[current]) // We push multiple pairs with the same vertex, but different distances. 
      continue;      // This vertex has already been popped (with shorter distance).

    // Important: mark vertices as visited after popping, not before pushing.
    // We continue updating the best distance for pushed vertices.
    visited[current] = 1;
    verticesCount++;
    edgeSum += dist[current];
    if (verticesCount == n){
      cout << edgeSum << endl;
      break;
    }

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

  cout << verticesCount << endl;
  if (verticesCount < n)  // The graph is not connected
    return -1;
  return edgeSum;
}

int main()
{
  scanf("%d %d %d", &n, &m, &k);

  for(int i = 0; i < n; i++){
    cin >> cities[i];
  }

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      cout << cities[i] << " " << cities[j] << " " << i << " " << j << endl;
      if(strncmp(cities[i],cities[j],m) == 0){
        neighbours[i].push_back(pair<int, int>(j, 1));
        neighbours[j].push_back(pair<int, int>(i, 1));
      }else{
        int counter = m;
        for(int h = k - m; h < k ; h++){
          if(cities[i][h] != cities[j][h]) counter++;
        }
        neighbours[i].push_back(pair<int, int>(j, counter));
        neighbours[j].push_back(pair<int, int>(i, counter));
      }
    }
  }

  printf("%d\n", prim(0));

  return 0;
}