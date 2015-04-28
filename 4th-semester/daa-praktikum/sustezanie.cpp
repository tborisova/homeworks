#include <iostream>
#include <queue>
using namespace std;

#define MAXN 2000

int n, bottles_size, holes_size, ella_x, ella_y, counter = 0;
bool visited[MAXN][MAXN] = {{false}};

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
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                visit.push(point(nx, ny, k.dist + 1));
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
	for(int i = 0; i < holes_size; i++){
		scanf("%d %d", &x, &y);
		visited[x][y] = true;
		holes[i] = point(x, y);
	}

	for(int i = 0; i < bottles_size; i++){
		scanf("%d %d", &x, &y);
		bottles[i] = point(x, y);
	}

	scanf("%d %d", &ella_x, &ella_y);

	for(int i = 0; i < bottles_size - 1; i++){
		path_counts[i] = bfs(point(bottles[i].x, bottles[i].y), point(ella_x, ella_y));
		if(path_counts[i] > 0){
			if(max < path_counts[i]){
				max = path_counts[i];
			}
			counter++;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				visited[i][j] = false;
			}
		}
		
		for(int i = 0; i < holes_size; i++){

			x = holes[i].x;
			y = holes[i].y;

			visited[x][y] = true;
		}
	}

	path_counts[bottles_size - 1] = bfs(point(bottles[bottles_size - 1].x, bottles[bottles_size - 1].y), point(ella_x, ella_y));
	if(path_counts[bottles_size - 1] > 0){
		counter++;
		if(max < path_counts[bottles_size - 1]){
			max = path_counts[bottles_size - 1];
		}
	}
	cout << counter << " " << max << endl;
	return 0;
}