#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

#define MAXN 8

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

int  n, end_x = 0, end_y = 7, start_x = 7, start_y = 0;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];


bool change_board(int x, int y){
	bool res = false;
	int i, j;
	for(int i = 7; i >= 0; i--){
		for(int j = 0; j < 8; j++){
			if(board[i][j] == 'T' && i == 7){
				board[i][j] = '.';
			}else if(i != 7 && board[i][j] == 'T'){
				if(i == x && j == y) res  = true;
				board[i][j] = '.';
				board[i+1][j] = 'T';
			}
		}
	}
	

	return res;
}

void printBoard(){
	for(int i = 0; i < 8;i++){
		for(int j = 0; j < 8;j++){
			cout << board[i][j];
		}
		cout << endl;
	}

	for(int i = 0; i < 8;i++){
		for(int j = 0; j < 8;j++){
			cout << visited[i][j];
		}
		cout << endl;
	}
}

int bfs(point start, point end) {
    if(start == end) {
        return true;
    }

    queue<point> visit;
    visit.push(start);
    visited[start.x][start.y] = true;

    while(!visit.empty()) {
    	point k = visit.front();
        visit.pop();
        if(k.x == -1){
        	change_board(k.x, k.y);
        }else{
        	if(k == end) return true;
        	if(board[k.x][k.y] == 'T'){
	        	 continue; 
        	}
			        
	    	int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
	        int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

	        visit.push(point(-1, -1));
	        for(int i = 0; i < 8; i++) {
	            int nx = k.x + dx[i];
	            int ny = k.y + dy[i];
	            if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8){
	            	if(board[nx][ny] != 'T'){
	            		visit.push(point(nx, ny));
	            	}else{
	            		visit.push(point(k.x, k.y));
	            	}
	            }
	        }	        
	    }        
    }

    return false;
}



int main()
{   int tests;
	scanf("%d", &tests);
	string row;
	
	int k = 0, i;

	while(tests){
		k = 0;
		// n = 8;
		while(k < 8){
			cin >> row;
			for(i = 0; i < 8; i++){
				board[k][i] = row[i];
			}
			k++;
		}

		for(int j = 0; j < 8;j++){
			for(int h = 0 ; h < 8;h++){
				visited[j][h] = false;
			}
		
		}
		// printBoard();
		if(bfs(point(start_x, start_y), point(end_x, end_y))){
			cout << "Alive" << endl;
		} else{
			cout << "Dead" << endl;
		}
		tests--;
	}
    return 0;
}