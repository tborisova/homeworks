#include <iostream>
using namespace std;

#define MAXN 300
#define INF INT_MAX/2

int n, m;
vector<pair<int, int> > neighbours[MAXN];
bool visited[MAXN];
int dist[MAXN];

int dijkstra(int start){
  for(int i = 1; i <= n; i++){
    dist[i] = INF;
  }

  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  pq.push(pair<int, int>(0, s));

  while(!pq.empty()){
    int current = pq.top().first;
  
    if (visited[current])
      continue;      

    visited[current] = 1;
    for(int i = 0; i < neighbours[current].size(); i++){
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      
      if(!visited[next]){
        if(dist[next] > dist[current] + edge){
          dist[next] = dist[current] + edge;
          visited[next] = true;
          pq.push(pair<int, int>(dist[next], next));
        }
      }
    }
  }
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    cin >> v1 >> v2 >> weight;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
    neighbours[v2].push_back(pair<int, int>(v1, weight));
  }

  for(int i = 1; i <=n; i++){
    dijkstra(i);
  }
}