#include <cstdio>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 512
// Infinity: INF + INF must not overflow
#define INF INT_MAX / 2

int a[N][N];
int n, m, q;
int used[N][N];

void dfs(){

}

void floyd()
{
  for (int k = 1; k<=n; k++){
    for (int i = 1; i<=n; i++)
      for (int j = 1; j<=n; j++){
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
  }
}

int main()
{
  int u, v, w;

  scanf("%d%d", &n, &m);
  // initialization before floyd
  for (int i = 1; i<=n; i++)
  for (int j = 1; j<=n; j++)
    a[i][j] = INF;
  for (int i = 1; i<=n; i++)
    a[i][i] = 0;

  //input
  for (int i = 0; i<m; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    a[u][v] = min(a[u][v], w); // ako a[u][v] e 2, a nie chetem 5, togava sthe презапишем 2 и после няма да получим резултата.
    a[u][v] = min(a[v][u], a[u][v]);
    a[v][u] = a[u][v];
  }

  floyd();

  // func();
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(a[i][j] != INF){
        cout << i << " " << j  << " "<< a[i][j] << endl;
      }else{
        cout << i << " " << j  << " "<< -1 << endl;
      }
    }
  }
  return 0;
}