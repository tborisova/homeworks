#include <iostream>
#include <queue>
using namespace std;

#define MAXN 150000

int main(){
  int n, m, town;
  long long sink_height, height;
  long long towns[MAXN];
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > cities;
  char ch;

  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> height;
    towns[i] = height;
    cities.push(pair<long long, int>(height, i));
  }

  cin >> m;
 
  for(int i = 0; i < m; i++){
    cin >> ch;
    if(ch == 'F'){
      if(n > 0){
        cout << cities.top().second << " " << cities.top().first << endl;
        cities.pop();
        n--;
      }else{
        cout << -1 << endl;
      }
    }else{
      cin >> town >> sink_height;
      cities.push(pair<long long, int>(towns[town] - sink_height, town));
      towns[town] -= sink_height;
    }
  }
}