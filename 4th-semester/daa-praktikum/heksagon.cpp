#include <cstdio>
#include <vector>
using namespace std;

#define N 500
vector<int> neighbours[N];
bool visited[N];
int n;
int old = 0, max = 0;

void dfs(int current)
{
  visited[current] = 1;
  for (int i = 0; i < neighbours[current].size(); i++)
  {
    int next = neighbours[current][i];
    if (!visited[next])
      current++;
      dfs(next);
      if(old > max){
        max = old;
      }
      old = 0;
  }
}

void dfsGraph()
{
  // int componentsCount = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      // componentsCount++;
    }
  }

  // return componentsCount;
}

int main()
{
  int m, i1, i2;
  scanf("%d%d", &n);
  for (int j = 0; j < 2*n - 1; j++)
  {

    scanf("%d", &i1);
    for(int i = 1; i < n; i++){
      scanf("%d", &i2);
      neighbours[i1].push_back(i2);
      neighbours[i2].push_back(i1); // if undirected graph
      if(j != 0){
        neighbours[i1].push_back(neighbours[i1-5][0]);
      }

      i1 = i2;
    }
  }

  // printf("%d\n", dfsGraph());
  dfsGraph();
  cout << max << endl;
  return 0;
}
