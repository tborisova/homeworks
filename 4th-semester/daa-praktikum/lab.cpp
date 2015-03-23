#include <cstdio>
#include <queue>
#define MAXN 1024

using namespace std;

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

int m, n, a, b, c, d;
bool floors[MAXN][MAXN] = {{0}};
bool visited[MAXN][MAXN] = {{0}};
char line[MAXN];

int bfs(point st, point en) {
    if(st == en) {
        return 0;
    }

    queue<point> visit;
    visit.push(st);
    visited[st.x][st.y] = true;

    while(!visit.empty()) {
        point k = visit.front();
        visit.pop();

        if(k == en) {
            return k.dist;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i = 0; i < 4; ++i) {
            int nx = k.x + dx[i];
            int ny = k.y + dy[i];

            if(nx > 0 && nx <= n && ny > 0 && ny <= m && !visited[nx][ny] && floors[nx][ny]) {
                visited[nx][ny] = true;
                visit.push(point(nx, ny, k.dist + 1));
            }
        }
    }

    return -1;
}


int main()
{
    scanf("%d%d%d%d%d%d", &m, &n, &a, &b, &c, &d);


    for(int j = 0; j < n; ++j) {
        scanf("%s", line);

        for(int k = 0; k < m; ++k) {
            floors[j + 1][k + 1] = (line[k] == '.');
        }
    }


    printf("%d\n", bfs(point(b, a), point(d, c)));

    return 0;
}
