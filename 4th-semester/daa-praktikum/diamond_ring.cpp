#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define N 1000
vector<int> neighbours[N];
bool visited[N] = {false};
int n, cycl = 0;

void dfs(int current, int parent)
{
  visited[current] = true;
  for (int i = 0; i < neighbours[current].size(); i++)
  { 
    if(cycl) return;
    int next = neighbours[current][i];
    cout << next << endl;
    if(visited[next] && next != parent){
          cycl = 1;
          return;
    }else if (!visited[next] && next != parent)
      dfs(next, current);
  }
}

void dfsGraph(int test)
{
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i]){
      dfs(i, - 1);
      if(cycl) break;
    }
  }

  if(cycl == 1){
    printf("Case #%d: Yes\n", test);
    cycl = 0;
  }else{
    printf("Case #%d: No\n", test);
  }
}

void clean(){

    for (int j = 1; j < n + 1; j++)
    { 
      for(int i = 0; i < neighbours[j].size(); i++){
        visited[neighbours[j][i]] = false;
        neighbours[j].pop_back();
      }
    }
}

int main()
{
  int m, i1, i2, neighbours_count, t, counter = 1;
  
  scanf("%d", &t);

  while(counter <= t){
    scanf("%d", &n);

    for (int j = 1; j < n + 1; j++)
    {
      scanf("%d", &neighbours_count);
      for(int i = 0; i < neighbours_count; i++){
        scanf("%d", &i1);
        neighbours[j].push_back(i1);
      }
    }
    
    dfsGraph(counter);
    
    counter++;

    clean();
  }
  return 0;
}
