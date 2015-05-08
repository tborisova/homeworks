#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[3][3];
// map <char, point> coordinates;
struct point{
  int x;
  int y;
  int dist;
  int parent_x;
  int parent_y;

  point(int _x = 0, int _y = 0, int _dist = 0, int _parent_x = -1, int _parent_y = -1) {
      x = _x;
      y = _y;
      dist = _dist;
      parent_x = _parent_x;
      parent_y = _parent_y;
  }

  bool operator==(const point& other) const {
        return x == other.x && y == other.y;
  }

  bool operator>(const point& other) const {
        return x > other.x && y > other.y;
  }

  bool operator<(const point& other) const {
        return x > other.x && y > other.y;
  }
};

char ordered_board[3][3] = {
  {'A', 'B', 'C'},
  {'D', 'E', 'F'},
  {'G', 'H', '.'}
};

int counter = 0;
bool visited[3][3];
char path[82];

char get_char(int x, int y){
  if(x == -1 && y == 0){
    return 'U';
  }
  if(x == 1 && y == 0){
    return 'D';
  }
  if(x == 0 && y == 1){
    return 'R';
  }
  if(x == 0 && y == -1){
    return 'L';
  }
}

bool board_is_ordered(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(board[i][j] != ordered_board[i][j]){
        return false;
      }
    }
  }

  return true;
}

void printBoard(){
  cout << "-----" << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << "-----" << endl;
}

char bfs(point current){

  priority_queue<pair<char, point>, vector<pair<char, point> >, greater<pair<char, point> > > visit;
  visit.push(pair<char, point>('0', current));
  visited[current.x][current.y] = 1;
  bool first = true;
  while(!visit.empty()){
    point k = visit.top().second;
    char move = visit.top().first;
    visit.pop();
    cout << move << endl;
    // if(k.parent_x)
    // cout << board[k.parent_x][k.parent_y] << " " << board[k.x][k.y] << " " << k.x  << " " << k.y << " " << k.parent_x << " " << k.parent_y << " " << move << endl;
    if(!first){
      board[k.parent_x][k.parent_y] = board[k.x][k.y];
      board[k.x][k.y] = '.';
    }
    first = false;
    printBoard();
    path[counter] = move;
    counter++;
    if(board_is_ordered()){
      return move;
    }

    if(move == 'Z'){
      return move;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char maxMove = 'Z';
    point maxPoint;
    for(int i =0; i < 4; i++){
      int nx = dx[i] + k.x;
      int ny = dy[i] + k.y;
      // cout << nx << " " << ny  <<" "<< k.parent_x << " " << k.parent_y << endl;
      if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && !(point(nx, ny) == point(k.parent_x, k.parent_y)) && !visited[nx][ny] ){
        // cout << "here"<< endl;
        point t = point(nx, ny, 0, k.x, k.y);
        char currentMove = get_char(dx[i], dy[i]);
        // cout << maxMove <<  " " << currentMove << " " << (maxMove > currentMove) << endl;
        if(maxMove > currentMove){
          maxMove = currentMove;
          maxPoint = t;
        }
      }
    }
    if(maxMove == 'Z'){
      return 'F';
    }else{
      visited[maxPoint.x][maxPoint.y] = true;
      visit.push(pair<char, point>(maxMove, maxPoint));
    }
  }
}

int main(){
  string line;
  int t;
  cin >> t;
  int x, y;

  while(t){
    for(int i = 0; i < 3; i++){
      cin >> line;
      for(int j = 0; j < 3; j++){
        board[i][j] = line[j];
        if(board[i][j] == '.'){
          x = i;
          y = j;
        }
        // coordinates[line[j]] = point(i, j);
      }
    }

    bfs(point(x, y, 0, x,y));
    // dfs(point(x, y), point(-1, -1), "0");
    for(int i = 1; i < counter - 1; i++){
      // cout << "endlddd" << endl;
      cout << path[i];
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        visited[i][j] = false;
        if(board[i][j] == '.'){
          x = i;
          y = j;
        }
      }
    }

    printBoard();
    bfs(point(0, 0, 0, 1, 0));
    
    for(int i = 0; i < counter; i++){
      // cout << "endlddd" << endl;
      cout << path[i];
    }

    cout << endl;
    
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        visited[i][j] = false;
        if(board[i][j] == '.'){
          x = i;
          y = j;
        }
      }
    }

    printBoard();
    bfs(point(1, 0, 0, 2, 0));
    
    for(int i = 0; i < counter; i++){
      // cout << "endlddd" << endl;
      cout << path[i];
    }

    cout << endl;
    

    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        visited[i][j] = false;
        if(board[i][j] == '.'){
          x = i;
          y = j;
        }
      }
    }

    printBoard();
    bfs(point(2, 0, 0, 2, 1));
    
    for(int i = 0; i < counter; i++){
      // cout << "endlddd" << endl;
      cout << path[i];
    }

    cout << endl;
    
    t--;
  }
}