#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

#define MIN 0
#define N 1001

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };

int dijkstra(int s)
{
  priority_queue<pair<int, int> > pq;
int last_dist = 0;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = 0;
  }
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));

  while (!pq.empty())
  {
    int current = pq.top().second;
    cout << current << " " << pq.top().first << endl;
    if(last_dist < pq.top().first){
      last_dist = pq.top().first;
    }
    pq.pop();
    if (visited[current])
      continue; 

    visited[current] = 1;
    for (int i = 0; i < neighbours[current].size(); i++)
    {
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if (!visited[next])
      {
        if (dist[next] < dist[current] + edge)
        {
          dist[next] = dist[current] + edge;
          pq.push(pair<int, int>(dist[next], next));
        }
      }
    }

  }
  return last_dist;
}

int main()
{
  int s, e;
  cin >> n >> m;

  int v1, v2, weight;
  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> weight;
    cout << "here " << endl;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
  }

  cout << dijkstra(1) << endl;

  return 0;
}