#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <algorithm>
using namespace std;

#define INF INT_MAX / 2
#define N 50001

int n, m;
vector<pair<int, int> > neighbours[N];
int dist[N];
bool visited[N] = { 0 };
int parent[N];
int maxp= 0, new_val = 1;

int dfs(int x, int dist){

    if(dist > maxp){
      maxp = dist;
      new_val = x;
    }
    for(int i = 0; i < neighbours[x].size(); i++){
        int next = neighbours[x][i].first;
        if(!visited[next]){
          visited[next] = true;
          dfs(next, dist+neighbours[x][i].second);
          visited[next] = false;
        }
    }
  
  return maxp;
}

int main()
{
  int s, e;
  cin >> n;

  int v1, v2, weight;
  for (int i = 0; i < n; i++)
  {
    cin >> v1 >> v2 >> weight;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
    neighbours[v2].push_back(pair<int, int>(v1, weight));
  }

  dfs(1, 0);
  cout << dfs(new_val, 0) << endl;
  return 0;
}