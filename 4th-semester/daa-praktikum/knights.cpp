#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 2000

int n, bottles_size, holes_size, ella_x, ella_y, bottles_reached = 0;
bool visited[MAXN][MAXN] = {{false}};
int bottles_dist[MAXN];
char board[MAXN][MAXN];

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

point bottles[MAXN], holes[MAXN];

int bfs(point start) {

    queue<point> visit;
    visit.push(start);
    visited[start.x][start.y] = true;

    while(!visit.empty()) {
        point k = visit.front();
        visit.pop();

        if(bottles_reached == bottles_size) return 1;

        int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for(int i = 0; i < 8; ++i) {
            int nx = k.x + dx[i];
            int ny = k.y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                visit.push(point(nx, ny, k.dist + 1));
                if(board[nx][ny] == 'B'){
                    bottles_dist[bottles_reached++] = k.dist + 1;
                }
            }
          }
      }
    

    return 0;
}

int main(){
  int path_counts[MAXN];
  int max = 0;
  scanf("%d %d %d", &n, &holes_size, &bottles_size);
  int x, y, sum = 0;

  for(int i = 0; i < n;i++){
    for (int j = 0; j < n; j++)
    {
      board[i][j] = '.';
    }
  }
  for(int i = 0; i < holes_size; i++){
    scanf("%d %d", &x, &y);
    visited[x][y] = true;
  }

  for(int i = 0; i < bottles_size; i++){
    scanf("%d %d", &x, &y);
   board[x][y] = 'B';
  }

  scanf("%d %d", &ella_x, &ella_y);

  bfs(point(ella_x, ella_y));
      cout << bottles_reached << " " << *max_element(bottles_dist, bottles_dist + bottles_size) << endl;
  return 0;
}