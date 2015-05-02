#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define MAXM 200000

int m;
map<string, bool> visited;
map<string, vector<string> > neighbours;
string savePath[MAXM*2];
map<string, bool> savedToPath;
int counter = 0;

void dfs(string task){
  cout << task << endl;
  counter++;
  for(int i = 0; i < neighbours[task].size(); i++){
    string depended_task = neighbours[task][i];
    if(!visited[depended_task]){
      visited[depended_task] = true;
      dfs(depended_task);
      visited[depended_task] = false;
    }
  }
}

bool myfunction (string i,string j) { return i.compare(j) > 0; }

void printInput(){
  map<string, vector<string> >::iterator it = neighbours.begin();
  vector<string>::iterator it2;

  while(it != neighbours.end()){
    cout << it->first << "depends on ";
    it2 = it->second.begin();
    while(it2 != it->second.end()){
      cout << *it2 << endl;
      it2++;
    }
    it++;
  }
}

int main(){
  string task, depended_task;
  cin >> m;
  vector<string> depended_task_count[MAXM];

  for(int i = 0; i < m; i++){
    cin >> task >> depended_task;
    visited[task] = false;
    visited[depended_task] = false;
    neighbours[task].push_back(depended_task);
  }

  map<string, vector<string> >::iterator it = neighbours.begin();
  int max_counter = 0;
  while(it != neighbours.end()){
    cout << "sttart " << endl;
    dfs(it->first);
    if(max_counter < counter) max_counter = counter;
    depended_task_count[counter].push_back(it->first);
    counter = 0;
    it++;
    cout << "sedettart " << endl;
  }

  for(int i = max_counter; i >=0; i--){
    sort(depended_task_count[i].begin(), depended_task_count[i].end(), myfunction);
    cout << i <<endl;
    while(!depended_task_count[i].empty()){
      cout << depended_task_count[i].back() << " ";
      depended_task_count[i].pop_back();
    }
    cout << endl;
  }
}