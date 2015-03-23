#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[500] = {0};

void bfs(int i){
  queue<int> q;
  visited[i] = 1;
  q.push(i);

  while(!q.empty()){
    vector<int> x = q.front();
    q.pop();
    for(int j = 0; j < x.size(); j++){
      if(!visited[x[j]]){
        q.push(x[j]);
        visited[x[j]] = 1;
      }
    }
    // za vseki sused 
    // proverqvame dali ne e poseten
    // slagame go v queueu
    // mark visited
  }
}

int main(){
  vector<vector<int>> graph;
  int counter = 0;
  
  scanf("%d %d", &n, &m);

  for(int i = 0; i < m; i++){
    scanf("%d %d", &one, &two);
    graph[one].insert(two);
  }

  for(int i  = 0; i < m; i++){
    if(!visited[i]){
      bfs(i + 1);
      counter++;
    }
  }

  int m, i1, i2;
  scanf("%d%d", &n, &m);
  for (int j = 0; j < m; j++)
  {
    scanf("%d%d", &i1, &i2);
    neighbours[i1].push_back(i2);
    neighbours[i2].push_back(i1); // if undirected graph
  }

  cout << counter << endl;
}
