#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1000

int islands[MAXN][MAXN] = { 0 };
int maxDist[MAXN] = { 0 }, savePath[MAXN];
int n;
int MAX_VALUE = 2000000000, from, to;
int parent[MAXN];
int dist[MAXN];
bool visited[MAXN];



void fillIslands(){
  int end_columns, end_rows, mid_row, j, i;
  bool transition = false;
  end_rows = 2*n - 1;
  end_columns = n;
  mid_row = end_rows/2;

  for(i = 0; i <= end_rows/2; i++){
    for(j = 0; j < end_columns; j++){
      scanf("%d", &islands[i][j]);
    }
    if(end_columns == end_rows) break;
  
    end_columns++;
  }

  end_columns = end_rows - 1;
  for(i = end_rows/2 + 1; i < end_rows; i++){
    for(j = 0; j < end_columns; j++){
      scanf("%d", &islands[i][j]);
    }
    end_columns--;
  }

}

void printWay(int node)
{
  if(parent[node] != from)
    printWay(parent[node]);
  cout << parent[node] << " ";
}

int main()
{  
  scanf("%d", &n);
  
  n = 2*n - 1;

  fillIslands();

  for(int i  = 0; i < n;i++){
    for (int j = 0; j < n; ++j)
    {
      cout << islands[i][j];
    }
    cout << endl;
  }
  // for(int i = 0; i < 2; i++){
  //   from = i;
  //   to = n - 1;
  //   Dijkstra(from);

  //   if(dist[to] == MAX_VALUE)
  //     cout << "No way exists from node " << from << " to node " << to << "!\n";
  //   else
  //   {
  //     // cout << dist[to] << endl;
  //     printWay(to);
  //     // cout << to << endl;
  //   }
  // }

  return 0;
}
