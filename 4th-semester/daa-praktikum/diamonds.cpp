#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define N 1001
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
    if(visited[next]){
          cycl = 1;
          return;
    }else if (!visited[next]){
      dfs(next, current);
      // visited[current] = false;
    }
  }
}

void dfsGraph(int test)
{
  for (int i = 1; i <= n; i++)
  {
    if(!visited[i]){
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

    for(int i = 1; i < n + 1; i++){
      visited[i] = false;
    }
    for (int j = 1; j < n + 1; j++)
    { 
      while(!neighbours[j].empty()){
        neighbours[j].pop_back();
      }
    }
    cycl = 0;
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