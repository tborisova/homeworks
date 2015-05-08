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
int parent[N], minTime = INF, path_counter, path_time, minPathparent[N], child[N];

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

void dfs(int s, int e, int time_p, int counter){
  if(s == e){
    path_time = time_p;
    path_counter = counter;
    return;
  }

  for(int i = 0; i < neighbours[s].size(); i++){
    int next = neighbours[s][i].first;
    int time_pass = neighbours[s][i].second;

    if(!visited[next]){
      visited[next] = true;
      parent[next] = s;
      dfs(next, e, time_p + time_pass, counter + 1);
      visited[next] = false;
    }
  }

  return;
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
    neighbours[v2].push_back(pair<int, int>(v1, weight));
  }

  int minPath = INF;

  while(1){
    dfs(1, 6, 0, 0);
    
    if(minPath > path_counter){
      minPath = path_counter;
      minTime = path_time;
      minPathparent[1] = -1;
      int tmp = n, counter = 0;
      while(tmp != 1){
        minPathparent[tmp] = parent[tmp];
        tmp = parent[tmp];
        visited[tmp] = true;
      }
      visited[1] = false;
      visited[n] = false;
    }else{
      minPath += 1;
      break;
    }
  }

  int tmp = n, sieze = minPath;
  cout << minTime << endl;
  while(minPath){
    child[minPathparent[tmp]] = tmp;

    tmp = minPathparent[tmp];
    minPath--;
  }

  cout << 1 << " ";
  for(int i = 1; i != 6; i=child[i] ){
    cout << child[i];
    if(i != 6){ 
      cout << " ";
    }else{
      break;
    }
  }
  cout << endl;
  return 0;
}