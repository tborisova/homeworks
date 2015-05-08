#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include <climits>

using namespace std;

#define INF 20010
#define N 10002

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };
int objects[N];

int dijkstra(int s)
{
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }
  dist[s] = 0;
  pq.push(pair<int, int>(0, s));

  while (!pq.empty())
  {
    int current = pq.top().second;
    pq.pop();
    visited[current] = 1;

    for (int i = 0; i < neighbours[current].size(); i++)
    {
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if(!visited[next] || s == next)
        if (dist[next] > dist[current] + edge){
            dist[next] = dist[current] + edge;
            pq.push(pair<int, int>(dist[next], next));
        }
    }
  }
  return 1;
}

int main()
{
  int s, e;
  int hospitals[101], h;
  cin >> n >> m >> h;

  if(m != 0){
    for(int i = 1; i <=n; i++) objects[i] = 0;

    for(int i = 0; i< h;i++){
      cin >> hospitals[i];
      objects[hospitals[i]] = 1;
    }

    int v1, v2, weight;
    for (int i = 0; i < m; i++)
    {
      cin >> v1 >> v2 >> weight;
      neighbours[v1].push_back(pair<int, int>(v2, weight));
      neighbours[v2].push_back(pair<int, int>(v1, weight));
    }

    int sum = 0;
    int minSum = INF;

    for(int i =0; i < h;i++){
      for(int j = 1; j <= n; j++){
        visited[j] = false;
      }
      dijkstra(hospitals[i]);
      sum = 0; 
      for(int j = 1; j <= n; j++){
        if(objects[j] != 1){
          sum += dist[j];
        }
      }

      if(minSum > sum) minSum = sum;
    }
    
    cout << minSum << endl;
  }else{
    cin >> h;
    cout << 1 << endl;
  }
  return 0;
}