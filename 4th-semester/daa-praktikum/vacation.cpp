#include <iostream>
#include <vector>
using namespace std;

#define N 300

vector<pair<int, int> > neighbours[N];
int visited[N];
int n, m;
int currentLen = 0, cycl =0, len = 0;

void dfs(int start, int current, int parent, int vertexesCount, int weight){
  if(current == start && vertexesCount >= 3){
    cycl = 1;
    len = weight;
    return;
  }
  cout << current << " " << vertexesCount << " " << currentLen << endl;
  for(int i = 0; i < neighbours[current].size(); i++){
    int next = neighbours[current][i].first;
    if(!visited[next]){
      visited[next] = true;
      cout << " here " << weight << " " << neighbours[current][i].second << endl;
      dfs(start, next, current, vertexesCount + 1, weight + neighbours[current][i].second);
      visited[next] = false;
    }else if(visited[next] && start == current && vertexesCount >= 3){
      cycl = 1;
      len = weight;
      return;  
    }
  }
}

int main(){
  int x, y, w;
  cin >> n >> m;

  for(int i =0; i < m; i++){
    cin >> x >> y >> w;
    neighbours[x].push_back(pair<int, int>(y, w));
    neighbours[y].push_back(pair<int, int>(x, w));
  }

  int minLen = 0;

  for(int i = 1; i <=n; i++){
    dfs(i, i, -1, 0, 0);
    if(cycl){
      if(minLen > len) minLen = len;
      cycl = 0;
      currentLen = 0;
      len= 0;
    }
    for(int i =1; i <=n;i++) visited[i] = false;
  }

  cout << minLen << endl;
}