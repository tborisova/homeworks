/* Dijkstra can be used only if edges are non-negative.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <cstdio>

using namespace std;

// Infinity: INF + INF must not overflow
#define INF INT_MAX / 2
#define MAXN 100
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

    bool operator<(const point& other) const {
        return dist < other.dist;
    }
};

int n, k;
bool visited[MAXN][MAXN];
int board[MAXN][MAXN], maxp = 0;

int dfs(int x, int y, int dist){

    if(dist > maxp) maxp = dist;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for(int i = 0; i < 4; i++){
      for(int j = 1; j <= k; j++){
        int nx = x + dx[i]*j;
        int ny = y + dy[i]*j;
        if(nx >= 0 && nx< n && ny >=0 && ny < n && board[x][y] < board[nx][ny] && !visited[nx][ny]){
          visited[nx][ny] = true;
          dfs(nx, ny, dist+board[nx][ny]);
          visited[nx][ny] = false;
        }
      }
    }
  
  return maxp;
}

int main()
{

  scanf("%d %d", &n, &k);

  for(int i = 0 ; i < n ; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &board[i][j]);
      visited[i][j] = false;
    }
  }

  cout << dfs(0,0,board[0][0]) << endl;

  return 0;
}