#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

#define MAXN 1000
#define MAXM 1000

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

int m, n, top_x, top_y, queen_x, queen_y, horse_x, horse_y;
int  board[MAXN][MAXM] = {{0}};
bool visited[MAXN][MAXM] = {{0}};

int bfs(point start, point end) {
    if(start == end) {
        return 0;
    }

    queue<point> visit;
    visit.push(start);
    visited[start.x][start.y] = true;

    while(!visit.empty()) {
        point k = visit.front();
        visit.pop();

        if(k == end) {
            return k.dist;
        }

        int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for(int i = 0; i < 8; ++i) {
            int nx = k.x + dx[i];
            int ny = k.y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                
                visited[nx][ny] = true;
                visit.push(point(nx, ny, k.dist + 1));
            }
        }
    }

    return -1;
}

int main()
{   

    scanf("%d%d%d%d%d%d%d%d", &n, &m, &horse_x, &horse_y, &queen_x, &queen_y, &top_x, &top_y);
   

    int horse_to_queen =  bfs(point(horse_x, horse_y), point(queen_x, queen_y));
    for(int i = 0; i< n; i++){
        for(int j=0; j< m;j++){
            visited[i][j] = false;
        }
    }
    int queen_to_top = bfs(point(queen_x, queen_y), point(top_x, top_y));

    for(int i = 0; i< n; i++){
        for(int j=0; j< m;j++){
            visited[i][j] = false;
        }
    }

    int horse_to_top = bfs(point(horse_x, horse_y), point(top_x, top_y));

    for(int i = 0; i< n; i++){
        for(int j=0; j< m;j++){
            visited[i][j] = false;
        }
    }

    int top_to_queen = bfs(point(top_x, top_y), point(queen_x, queen_y));

    printf("%d\n", min(horse_to_queen + queen_to_top, horse_to_top + top_to_queen));
    return 0;
}
