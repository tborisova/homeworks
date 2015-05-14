#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

int main(){
  int n;
  string line;
  scanf("%d", &n);

  priority_queue<pair<string, int>, vector<pair<string, int> >, greater<pair<string, int> > > events;
  for(int i = 0; i < n; i++){
    cin >> line;
    events.push(pair<string, int>(line, i + 1));
  }
  
  while(!events.empty()){
    cout << events.top().second << endl;
    events.pop();
  }

}