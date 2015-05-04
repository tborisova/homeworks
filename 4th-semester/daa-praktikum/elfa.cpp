#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000

vector<pair<int, int> > neighbours[MAXN];
int maxpath = 0;
int n,m;
bool visited[MAXN];

void dfs(int street,  int length, int parent){
  if(maxpath < length) maxpath = length;
  if(maxpath >= 999*m) return;
  for(int i = 0; i < neighbours[street].size(); i++){
    int next = neighbours[street][i].first;
    if(!visited[next] && parent != next){
      visited[next] = true;
      dfs(next, length + neighbours[street][i].second, street);
      visited[next] = false;
    }
  }

}

int main(){
  int length, v1, v2;
  cin >> n >> m;

  for(int i = 1; i <=m;i++){
    cin >> v1 >> v2 >> length;
    visited[v1] = false;
    visited[v2] = false;
    neighbours[v1].push_back(pair<int, int>(v2, length));
  }

  dfs(1, 0 , -1);

  cout << maxpath;
}