#include <iostream>
#include <vector>
using namespace std;

#define N 100000

int n, m;
vector<int> neighbours[N];
int dist[N];
bool visited[N] = { 0 };
int parent[N];
int maxp= 0, new_val = 1;

int dfs(int x, int dist, int parent){

    if(dist > maxp){
      maxp = dist;
      new_val = x;
    }
    cout << " " << x << " " << dist << endl;
    for(int i = 0; i < neighbours[x].size(); i++){
        int next = neighbours[x][i];
        if(!visited[next] && next != parent){
          visited[next] = true;
          dfs(next, dist+1, parent);
          visited[next] = false;
        }
    }
  
  return maxp;
}

int main(){
  int x, y, max = 0;
  int numbers[N][2];
  int i = 0;

  while(cin >> x >> y){
    numbers[i][0] = x;
    numbers[i][1] = y;
    i++;
    if(max < x) max = x;
  }

  for(int j = 0; j < i; j++){
    for(int k = 0; k < i; k++){
      if(j != k){
        int event_start = numbers[j][0];
        int event_end = numbers[j][1];
        if(event_start + event_end <= numbers[k][0]){
          neighbours[event_start].push_back(numbers[k][0]);
        }
      }
    }
  }

  n = max;

  cout << " ddd ddd" << endl;
  dfs(1, 0, -1);
  cout << "dkadmkd" << endl;
  cout << dfs(new_val, maxp, -1) << endl;
  cout << maxp << "www " << endl;
  // printf("%d\n", dfsGraph());
  for(int i = 1; i <= max + 1; i++){
    if(neighbours[i].size()){
      cout << i <<  " ";
      while(!neighbours[i].empty()){
        cout << neighbours[i].back() << " ";
        neighbours[i].pop_back();
      }
    }
    cout << endl;
  }

}