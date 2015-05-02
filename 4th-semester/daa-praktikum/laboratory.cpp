#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1001
#define MAXM 1001

int n, m;
bool visited[MAXN][MAXM];
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

int bfs(point start, point end){
  if(start == end) return 0;

  queue<point> visit;
  visit.push(start);
  visited[start.x][start.y] = true;

  while(!visit.empty()){
    point k = visit.front();
    visit.pop();

    if(k == end) return k.dist;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i < 4; i++){
      int nx = k.x + dx[i];
      int ny = k.y + dy[i];
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
          visited[nx][ny] = true;
          visit.push(point(nx, ny, k.dist + 1));
      }
    }
  }

  return -1;
}

int main(){
  int a,b,c,d;
  scanf("%d %d %d %d %d %d", &m, &n, &a, &b, &c, &d);
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
    }
  }

  cout << bfs(point(b-1, a-1), point(d-1, c-1)) << endl;
}