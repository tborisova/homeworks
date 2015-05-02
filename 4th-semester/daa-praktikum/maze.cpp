#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1001
#define MAXM 1001

int n, m, prevx = 0, prevy = 0;
bool visited[MAXN][MAXM];
int con = 0;

struct point {
    int x, y, dist;

    point(int _x = 0, int _y = 0, int _dist = 0) {
        x = _x;
        y = _y;
        dist = _dist;
    }

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }
};

void dfs(point start)
{

  visited[start.x][start.y] = 1;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  for (int i = 0; i < 4; i++)
  {
      int nx = start.x + dx[i];
      int ny = start.y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
        dfs(point(nx, ny));
        con++;
      }else{
        return;
      }
  }

  return;
}

void dfsGraph()
{
  int max_t = 0, new_t = 0;
  for (int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++){
      
      if(!visited[i][j]){
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++)
        {

          int nx = start.x + dx[i];
          int ny = start.y + dy[i];
          if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
            counter++;
          }
        }
        
        if(counter != 1){
          dfs(point(i, j));
          points++;
        }
      }
    }
  }

  return;
}

int main(){
  int a,b,c,d;
  scanf("%d %d", &m, &n);
  char ch;
  string line;
  for(int i = 0; i < n;  i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      if(line[j] == '#'){
        visited[i][j] = true;
      }else{
        visited[i][j] = false;
      }
      paths_count[i][j] = 0;
    }
  }
  
  dfsGraph();
  
  int max_t = 0;

  for(int i = 0; i < prevx; i++){
    for(int j = 0; j < prevy; j++){
      if(max_t < paths_count[i][j]){
        max_t = paths_count[i][j];
      }
    }
  }
  cout << max_t  - 1<< endl;
}