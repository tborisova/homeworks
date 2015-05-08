#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
  priority_queue<int, vector<int>, greater<int> > pq;
  int num, n;

  cin >> n;

  while(n){
    cin >> num;
    pq.push(num);
    n--;
  }
  
  while(!pq.empty()){
    cout << pq.top();
    if(pq.size() > 1){
      cout << " ";
    }
    pq.pop();
  }
}