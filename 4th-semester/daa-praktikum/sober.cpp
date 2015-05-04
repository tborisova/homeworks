#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 50000

int visited[MAXN];
int savedPath[MAXN];
int parent[MAXN];
vector<pair<int, int> > neighbours[MAXN];
int n, m, x, y, z, savedPathLenght = 0;

int bfs(int s, int e, int dist){
  if(s == e){
    return dist;
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > visit;
  visited[s] = true;
  visit.push(pair<int, int>(dist, s));

  while(!visit.empty()){
    pair<int, int> p = visit.top();
    visit.pop();
    if(p.second == e){
      return p.first;
    }

    for(int i = 0; i < neighbours[p.second].size(); i++){
      pair<int, int> next = neighbours[p.second][i];
      if(!visited[next.first]){
        visited[next.first] = true;
        parent[next.first] = p.second;
        visit.push(pair<int, int>(next.second + p.first, next.first));
      }
    }
  }

  return -1;
}

void printPath(){
  int tmp = z;
  int new_p = 0;
  int counter = 0;

  while(tmp != -1){
    new_p = parent[tmp];
    savedPath[counter] = tmp;
    tmp = new_p;
    counter++;
  }
  
  counter--;

  for(int i = counter; i >= 0; i--){
    cout << savedPath[i] << " ";
  }
  cout << endl;
}

int main(){
  int v1, v2, weight;
  cin >> n >> m >> x >> y >> z;

  for(int i = 0; i < m; i++){
    cin >> v1 >> v2 >> weight;
    neighbours[v1].push_back(pair<int, int>(v2, weight));
  }

  int x_to_y = bfs(x, y, 0);
  parent[x] = -1;

  for(int i = 0; i < n; i++)
    visited[i] = false;

  int y_to_z = bfs(y, z, 0);

  if(x_to_y != -1 && y_to_z != -1){
    cout << x_to_y + y_to_z << endl;
    printPath();
  }else{
    cout << -1;// << endl;
  }
}