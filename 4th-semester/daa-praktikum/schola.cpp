#include<cstdio>
#include<vector>
using namespace std;

#define N 500
vector<int> neighbours[N];
bool visited[N];
int n;

void dfs(int current)
{
  visited[current] = 1;
  for (int i = 0; i < neighbours[current].size(); i++)
  {
    int next = neighbours[current][i];
    if (!visited[next])
      dfs(next);
  }
}

int dfsGraph()
{
  int componentsCount = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      componentsCount++;
    }
  }

  return componentsCount;
}

int main()
{
  int m, i1, i2;
  scanf("%d%d", &n, &m);
  for (int j = 0; j < m; j++)
  {
    scanf("%d%d", &i1, &i2);
    neighbours[i1].push_back(i2);
    neighbours[i2].push_back(i1);
  }

  printf("%d\n", dfsGraph());
  return 0;
}