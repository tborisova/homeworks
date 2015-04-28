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

void Dijkstra(int node)
{
  int min_dist, i;
  for(i = 0; i < n; i++)
  {
    dist[i] = 0;
    visited[i] = 0;
  }
  dist[node] = MAX_VALUE;

  for(;;)
  {
    cout << "ddd"<<endl;
    min_dist = -1;
    for(i = 0; i < n; i++)
      if(dist[i] > min_dist && !visited[i])
      {
        node = i;
        min_dist = dist[i];
      }
    cout << node << endl; 
    if(min_dist == -1)
      return;
    visited[node] = 1;

    for(i =0; i < n; i++)
      if(islands[node][i] && (dist[i] < min(dist[node], islands[node][i])))
        dist[i] = min(dist[node], islands[node][i]);
  }

}


void printIslands(){
  int end_rows = 2*n - 1;

  for(int i = 0; i < end_rows; i++){
    for(int j = 0; j < end_rows; j++){
      cout << islands[i][j] << " ";
    }
    cout << endl;
  }
}

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

  for(int i = 0; i < 2; i++){
    from = i;
    to = n - 1;
    Dijkstra(from);

    if(dist[to] == MAX_VALUE)
      cout << "No way exists from node " << from << " to node " << to << "!\n";
    else
    {
      // cout << dist[to] << endl;
      printWay(to);
      // cout << to << endl;
    }
  }

  return 0;
}
