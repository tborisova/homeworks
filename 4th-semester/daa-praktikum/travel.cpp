#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAXN 300
#define MAXM 20000

vector<pair<int, int> > neighbours[MAXN];
int n, m, minpath = -1, counter = 0;

void dfs(int s, int e, int dist){

  if(minpath > dist){
    minpath = dist;
  }

  if(s == e){
    return;
  }

  for(int i =0; i< neighbours[s].size(); i++){
    next = neighbours[s];
  }
}

void bfs(int s){
  
}


int main(){
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    cin >> x >> y >> w;
    neighbours[x].push_back(pair<int, int>(y, w));
  }
}