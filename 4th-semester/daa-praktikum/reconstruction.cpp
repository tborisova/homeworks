#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <climits>
#include <map>
#include <cmath>

using namespace std;

#define INF INT_MAX
#define N 10001

int n, m, k;
map<string, vector<pair<string, int> > > neighbours;
map<string, int> dist;
map<string, bool> visited;
long long prim(string s)
{
  priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;

  for (map<string, vector<pair<string, int> > >::iterator i = neighbours.begin(); i != neighbours.end(); i++)
  {
    dist[i->first] = INF;
    visited[i->first] = false;
  }
  dist[s] = 0;
  pq.push(pair<int, string>(0, s));
  int verticesCount = 0;
  long long edgeSum = 0;

  while (!pq.empty())
  {
    string current = pq.top().second;
    pq.pop();
    if (visited[current])
      continue;

    visited[current] = true;
    verticesCount++;
    edgeSum += dist[current];
    if (verticesCount == n)
      break;
    for (int i = 0; i < neighbours[current].size(); i++)
    {
      string next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if (!visited[next])
      {

        if (dist[next] > edge)
        {
          dist[next] = edge;
          pq.push(pair<int, string>(dist[next], next));
        }
      }
    }

  }
  if (verticesCount < n)
    return -1;
  return edgeSum;
}

int main()
{
  scanf("%d %d %d", &n, &m, &k);
  int weight;
  string v1, v2, first1, first2;

  cin >> first1 >> first2;
  neighbours[first1].push_back(pair<string, int>(first2, 0));
  neighbours[first2].push_back(pair<string, int>(first1, 0));

  for (int i = 1; i < m; i++)
  {
    cin >> v1 >> v2;
    neighbours[v1].push_back(pair<string, int>(v2, 0));
    neighbours[v2].push_back(pair<string, int>(v1, 0));
  }
  for (int i = 0; i < k; i++)
  {
    cin >> v1 >> v2 >> weight;

    neighbours[v1].push_back(pair<string, int>(v2, weight));
    neighbours[v2].push_back(pair<string, int>(v1, weight));
  }

  printf("%lld\n", prim(first1));

  return 0;
}