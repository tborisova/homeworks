#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

#define MAXN 8
int tests;
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
bool done = false;


void printBoard(){
	for(int i = 0; i < 8;i++){
		for(int j = 0; j < 8;j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

void make_move(point new_position, point old_position){
    int i, j;
    board[old_position.x][old_position.y] = '.';
    board[new_position.x][new_position.y] = 'G';
    for(int i = 7; i >= 0; i--){
      for(int j = 0; j < 8; j++){
        if(board[i][j] == 'T' && i == 7){
          board[i][j] = '.';
        }else if(i != 7 && board[i][j] == 'T'){
          board[i][j] = '.';
          board[i+1][j] = 'T';
        }
      }
  }
}

void go_back(point new_position, point old_position){
    int i, j;
    board[old_position.x][old_position.y] = 'G';
    board[new_position.x][new_position.y] = '.';
    for(int i = 7; i >= 0; i--){
      for(int j = 0; j < 8; j++){
          if(board[i][j] == 'T'){
            board[i-1][j] = 'T';
            // board[i][j] = '.';
          }
      }
  }
}

bool empty_board(){
  for(int i = 0; i <= 7; i++){
    for(int j = 0; j <= 7; j++){
      if(board[i][j] == 'T') return false;
    }
  }

  return true;
}
void dfs(point start, point end){

  if(start == end){
    done = true;
    return;
  }

  if(empty_board()){
    done = true;
    return;
  }

  // cout << start.x << " " << start.y << endl;
  // printBoard();
  int dx[9] = {-1, -1, -1, 0, 0, 1, 1, 1,1};
  int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0 ,1};

  for (int i = 0; i < 9; i++){
    int nx = dx[i] + start.x;
    int ny = dy[i] + start.y;
    // cout << "new " << nx << " " << ny << endl;
    if(nx >= 0 && nx  <= 7 && ny >= 0 && ny <= 7 &&  (nx-1) >=0 && (nx-1) <=7 && !visited[nx][ny] && board[nx-1][ny] != 'T' && board[nx][ny] != 'T'){
      visited[nx][ny] = true;
      make_move(point(nx, ny), start);
      dfs(point(nx, ny), end);
      go_back(point(nx, ny),start);
      visited[nx][ny] = false;
    }
  }

  return;
}

int main()
{   
	scanf("%d", &tests);
	string row;
	
	int k = 0, i;

	while(tests){
		k = 0;
		// n = 8;
		while(k < 8){
			cin >> row;
			for(i = 0; i < 8; i++){
                          // if(row[i] == 'T') cout << "dldlkdk" << endl;
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
            dfs(point(start_x, start_y), point(end_x, end_y));
		
            if(!done){
			cout << "Dead" << endl;
		} else{
			cout << "Alive" << endl;
		}
            done = false;
		tests--;
	}
    return 0;
}