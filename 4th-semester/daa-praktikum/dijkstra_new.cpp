#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

#define INF INT_MAX / 2
#define N 50001

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };
int parent[N];

int dijkstra(int s, int e)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
    parent[i] = -1;
  }
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));

  while (!pq.empty())
  {
    int current = pq.top().second;
    pq.pop();
    if (visited[current])
      continue;      
    if (current == e)
      break;

    visited[current] = 1;
    for (int i = 0; i < neighbours[current].size(); i++)
    {
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if (!visited[next])
      {
        if (dist[next] > dist[current] + edge)
        {
          dist[next] = dist[current] + edge;
          parent[next] = current;
          pq.push(pair<int, int>(dist[next], next));
        }
      }
    }

  }
  if (dist[e] == INF)
    return -1;
  return dist[e];
}

int main()
{
  int s, e;
  cin >> n >> m >> s >> e;

  int v1, v2, weight;
  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> weight;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
    neighbours[v2].push_back(pair<int, int>(v1, weight));
  }

  cout << dijkstra(s, e) << endl;

  return 0;
}