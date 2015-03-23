#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define N 500
vector<int> neighbours[N];
bool visited[N];
int n, counter = 0;

void bfs(int current)
{
  visited[current] = 1;
  queue<int> elements;
  elements.push(current);

  while(!elements.empty()){
    counter++;
    int next = elements.front();
    elements.pop();
    for(int i = 0; i < neighbours[next].size(); i++){
      next = neighbours[current][i];
      if(!visited[next]){
        elements.push(next);
        visited[next] = 1;
      }
    }
  }
}

int main()
{
  int m, i1, i2;
  scanf("%d%d", &n, &m);
  for (int j = 1; j < m+1; j++)
  {
    scanf("%d%d", &i1, &i2);
    neighbours[i1].push_back(i2);
    neighbours[i2].push_back(i1);
  }

  bfs(1);

  printf("%d\n", counter);
  return 0;
}
