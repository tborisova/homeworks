#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 200000

vector<int> neighbours[MAXN];
int time_for_task[MAXN];
bool visited[MAXN];
int n;

int bfs(int k) {
      for(int i = 0; i < neighbours[k].size(); ++i) {
          int next = neighbours[k][i];
          if(!visited[next]){
             visited[next] = true;
             bfs(next);
             cout << k << " " << next << endl;
             time_for_task[k] += time_for_task[next];
          }
      }
    return 0;
}
void printTasks(){
  int depended_task;
  for(int i = 0; i < n;i++){
    cout << i << " will finish in " << time_for_task[i] << " depended_tasks: ";
    while(!neighbours[i].empty()){
      depended_task = neighbours[i].back();
      neighbours[i].pop_back();
      cout << depended_task << " ";
    }

    cout << endl;
  }
}

int main(){
  int task_time, depended_task, depended_tasks_count;

  scanf("%d", &n);

  for(int i=0;i<n;i++){

    scanf("%d %d", &task_time, &depended_tasks_count);
    time_for_task[i] = task_time;
    visited[i] = false;
    for(int j = 0; j < depended_tasks_count; j++){
      scanf("%d", &depended_task);
      neighbours[i].push_back(depended_task);
    }
  }

  // for(int i = 0; i <n;i++){
  //   bfs(i);
  //   cout << time_for_task[i] << endl;
  // }

  bfs(4);
  cout << time_for_task[4] << endl;
}