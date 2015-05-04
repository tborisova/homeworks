#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include <climits>

using namespace std;

#define INF INT_MAX / 2
#define N 50001

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };

int dijkstra(int s, int e)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  for (int i = 0; i <= n-1; i++)
  {
    dist[i] = INF;
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
  int s, e, k;
  cin >> n >> m >> k; 

  int v1, v2, weight;
  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2;
    neighbours[v1].push_back(pair<int, int>(v2, 0));
    neighbours[v2].push_back(pair<int, int>(v1, 0));
  }

  for (int i = 0; i < k; i++)
  {
    cin >> v1 >> v2;
    neighbours[v1].push_back(pair<int, int>(v2, 1));
    neighbours[v2].push_back(pair<int, int>(v1, 1));
  }
  cout << dijkstra(0, n-1) << endl;

  return 0;
}