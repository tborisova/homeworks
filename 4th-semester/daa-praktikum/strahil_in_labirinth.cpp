#include <iostream>
#include <cstdio>
using namespace std;

#define MAXM 1000
#define MAXN 1000

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

    bool operator!=(const point& other) const {
        return x != other.x && y != other.y;
    }
};

bool visited[MAXN][MAXM];
char board[MAXN][MAXM];
int m, n, maxp = 0;
int new_x = 0, new_y = 0;

void printInput(){

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << board[i][j];
    }

    cout << endl;
  }
}

int dfs(point k){

    if(k.dist > maxp){
      maxp = k.dist;
      new_x = k.x;
      new_y = k.y;
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int i = 0; i < 4; i++){
        int nx = dx[i] + k.x;
        int ny = dy[i] + k.y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] != '#' ){
          visited[nx][ny] = true;
          dfs(point(nx, ny, k.dist + 1));
          // visited[nx][ny] = false;
        }
    }
  
  return maxp;
}

int main(){
  string line;
  bool found = false;
  cin >> m >> n;

  for(int i = 0; i < n; i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      board[i][j] = line[j];
    }
  }

  int i, j;

  for(i = 0; i < n;i++){
    for(j = 0; j < m; j++){
      if(board[i][j] != '#'){
        found = true;
        break;
      }
    }
    if(found) break;
  }

  dfs(point(i, j, 0));

  if(i != new_x && j != new_y){
    cout << dfs(point(new_x, new_y, 0)) << endl;
  }else{
    cout << maxp << endl;
  }
}