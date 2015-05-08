#include <iostream>
#include <map>
using namespace std;

#define MAXN 19

int board[MAXN][MAXN];
map<string, int> cells;
int n;

void make_move(string player, int x, int y){
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  board[x][y] = cells[player];

  for(int i = 0; i < 4; i++){
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if(nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] != 0){
      board[nx][ny] = cells[player];
    }
  }
}

pair<int, int> get_xy(){
  for(int i =0; i< n; i++){
    for(int j =0; j< n;j++){
      if(board[i][j] == 0) return pair<int, int>(i,j);
    }
  }
}

bool board_full(){
  for(int i =0; i< n; i++){
    for(int j =0; j< n;j++){
      if(board[i][j] == 0) return false;
    }
  }

  return true;
}

string play(int n){
  int start_x = 0;
  int start_y = 0;
  string player = "Elly";

  while(!board_full()){
    make_move(player, start_x, start_y);
    if(board_full()){
      return player;
    }
    if(player.compare("Elly")){
      player = "Krisi";
    }else{
      player = "Elly";
    }
    pair<int, int> p = get_xy();
    start_x = p.first;
    start_y= p.second;
  }

  if(player.compare("Elly")){
    return "Krisi";
  }else{
    return "Elly";
  }
}

int main(){
  int t;
  cells["Elly"] = 1;
  cells["Krisi"] = 2;

  cin >> t;

  while(t){
    
    cin >> n;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        board[i][j] = 0;
      }
    }

    cout << play(n) << endl;
    t--;
  }
}