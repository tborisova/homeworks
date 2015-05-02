#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

#define N 200000
vector<int> neighbours[N];
bool visited[N];
int time_to_finish[N];
int n;
int max_t;

int bfs(int task) {

    queue<int> visit;
    visit.push(task);
    max_t = 0;
    visited[task]= true;
    while(!visit.empty()) {
        int k = visit.front();
        visit.pop();
        cout << "task " << k << " time to finish " << time_to_finish[k] << endl;
        for(int i = 0; i < neighbours[k].size(); i++){
          if(visited[i]){
            time_to_finish[task] += time_to_finish[i];
          }else{
            visited[task]= true;
            visit.push(i);
          }
        }
        cout << "end of task " << task << endl; 
    return 0;
}

int main()
{
  int m, i1, time_to_finish_task, count_of_neighbours;
  scanf("%d", &n);
  for (int j = 0; j < n; j++)
  {
    scanf("%d%d", &time_to_finish_task, &count_of_neighbours);
    time_to_finish[j] = time_to_finish_task;
    while(count_of_neighbours){
      scanf("%d", &i1);
      neighbours[j].push_back(i1);
      count_of_neighbours--;
    }
  }

  for(int j = 0; j < n;j++){
    bfs(j);
    cout << time_to_finish[j] << endl;
  }
  return 0;
}
