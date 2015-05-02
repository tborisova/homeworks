#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdio>
using namespace std;

#define MAXN 1001
#define MAXM 1001

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

int n, m, t, bad_apples_count = 0;
point bad_apples[2];
int visited[MAXN][MAXM], temp_t;
bool board[MAXN][MAXM];

void bfs(point start){

    queue<point> visit;
    visit.push(start);
    visited[start.x][start.y] = true;

    while(!visit.empty()) {
        point k = visit.front();
        visit.pop();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        if(k.dist == t){
          continue;
        }
        for(int i = 0; i < 4; ++i) {
            int nx = k.x + dx[i];
            int ny = k.y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                visit.push(point(nx, ny, k.dist + 1));
                board[nx][ny] = true;
            }
          }
      }
    
    return;
}

int main(){
  int x,y;
  scanf("%d %d %d", &n, &m, &t);

  while(cin >> x >> y){
    bad_apples[bad_apples_count] = point(x, y);
    bad_apples_count++;
  }

  for(int i = 0; i < bad_apples_count; i++){
    bfs(bad_apples[i]);
    board[bad_apples[i].x][bad_apples[i].y] = true;
    for(int i = 1; i <= n;i++){
      for(int j = 1; j <= m;j++){
        visited[i][j] = false;
      }
    }
  }


  int counter = 0;
  for(int i=1;i<=n;i++){
    for(int j =1;j <= m;j++){
      if(board[i][j]){
         counter++;
      }
    }
  }

  cout << m*n - counter << endl;
}
