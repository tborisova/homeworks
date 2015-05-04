#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include <climits>

using namespace std;

#define INF INT_MAX / 2
#define N 513

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };

int dijkstra(int s, int e)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  pq.push(pair<int, int>(dist[s], s));

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
  int s, e;
  cin >> n >> m;

  int v1, v2, weight;
  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> weight;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
  }

  int q;
  cin >> q;

  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
  }
  while(q){
    cin >> s >> e;
    if(dist[s] == INF)
      dist[s] = 0;
    int res = dijkstra(s, e);
    if(res == -1){
      cout << "unreachable" << endl; 
    }else{
      cout <<  res << endl;
    }
    q--;
  }
  return 0;
}