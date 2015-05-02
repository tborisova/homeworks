#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1000
#define MAXM 1000

int n,m;

char first_floor[MAXN][MAXM];
char maze_floor[MAXN][MAXM];
char stairs[MAXN][MAXM];
char *current_board[MAXN];

struct point {
    int x, y, dist, etaj;

    point(int _x = 0, int _y = 0, int _dist = 0, int _etaj = 1) { // 1 - first, 0 - maze
        x = _x;
        y = _y;
        dist = _dist;
        etaj = _etaj;
    }

    bool operator==(const point& other) const {
        return x == other.x && y == other.y && other.etaj == etaj;
    }
};

point end_p;

void print(){

  for(int i = 1; i <= n;i++){
    for(int j = 1; j <= m; j++){
      cout << first_floor[i][j];
    }
    cout << endl;
  }
 cout << endl;
 for(int i = 1; i <= n;i++){
    for(int j = 1; j <= m; j++){
      cout << maze_floor[i][j];
    }

    cout << endl;
  }
 cout << endl;
 for(int i = 1; i <= n;i++){
    for(int j = 1; j <= m; j++){
      cout << stairs[i][j];
    }
    cout << endl;
  }

}

int bfs(point start){

  if(start == end_p){
    return 0;
  }

  queue<point> visit;
  visit.push(start);
  first_floor[start.x][start.y] = '#';

  while(!visit.empty()){
    point k = visit.front();
    visit.pop();
    if(k == end_p){
      return k.dist;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    cout << k.x << " " << k.y << " " << k.etaj << " " << k.dist << endl;
    for(int i = 0; i < 4; i++){
      int nx = k.x + dx[i];
      int ny = k.y + dy[i];

      if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
        if(k.etaj == 1){
          if(first_floor[nx][ny] == '.'){
            first_floor[nx][ny] = '#';
            visit.push(point(nx, ny, k.dist + 1, 1));
          }
        }else{
          if(maze_floor[nx][ny] == '.'){
            maze_floor[nx][ny] = '#';
            visit.push(point(nx, ny, k.dist + 1, 0));
          }
        }

        if(stairs[nx][ny] == 'd' && k.etaj == 1 && maze_floor[nx][ny] != '#'){
          maze_floor[nx][ny] = '#';
          visit.push(point(nx, ny, k.dist + 1, 0));
        }

        if(stairs[nx][ny] == 'u' && k.etaj == 0 && first_floor[nx][ny] != '#'){
          first_floor[nx][ny] = '#';
          visit.push(point(nx, ny, k.dist + 1, 1));
        }
        
        if(stairs[nx][ny] == 'b'){
          if(maze_floor[nx][ny] != '#'){
            maze_floor[nx][ny] = '#';
            visit.push(point(nx, ny, k.dist + 1, 0));
          }

          if(first_floor[nx][ny] != '#'){
            first_floor[nx][ny] = '#';
            visit.push(point(nx, ny, k.dist + 1, 1));
          } 
        }
      }
    }
  }

  return -1;
}

int main(){
  int a, b, c, d;
  string line;

  scanf("%d %d %d %d %d %d", &m, &n, &a, &b, &c, &d);
  end_p = point(d,c);

  for(int i = 1; i <= n;i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      first_floor[i][j+1] = line[j];
    }
  }
 
 for(int i = 1; i <= n;i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      maze_floor[i][j+1] = line[j];
    }
  }
 
 for(int i = 1; i <= n;i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      stairs[i][j+1] = line[j];
    }
  }

  cout << bfs(point(b, a)) << endl;
}
