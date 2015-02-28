// this file shows work of sortQueue and mergeQueue
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

#include "queue_linked.cpp"
#include "sortQueue.cpp"
#include "mergeQueue.cpp"

struct people{
  char name[32];
  int age;
  bool operator<(const people& p) const{
    return age < p.age;
  }
  bool operator!=(const people& p) const{
    return age != p.age;
  }
};

typedef queue<people> pqueue;

// template <typename T> queue<T> void queue<people>::print(){
//   people x;
//   while(!empty()){
//     pop(x);
//     cout << setw(35) << x.name << setw(15) << x.age << endl;
//   }
// }

int main(){
  queue<pqueue> qq;
  int m;
  int n;
  cout << "m = ";
  cin >> m;

  for(int j=0;j<m;j++){
    pqueue q;
    cout << j << " queue:\n n = ";
    cin >> n;
    for(int i=0;i < n;i++){
      people s;
      cout << "Name: ";
      cin.ignore();
      cin.getline(s.name, 32);
      cout << "Age: ";
      cin >> s.age;
      q.push(s);
    }
    qq.push(q);
  }

  queue<pqueue> qq1;

  while(!qq.empty()){
    pqueue r;
    qq.pop(r);
    pqueue t;
    sortQueue(r,t);
    qq1.push(t);
  }

  pqueue merge_queue, help_queue;
  qq1.pop(merge_queue);
  people dummy = {"xxxx", -1};

  while(!qq1.empty()){
    qq1.pop(help_queue);
    merge_queue = merge(merge_queue, help_queue, dummy);
  }

  people x;
  pqueue people_queue;
  while(!merge_queue.empty()){
    merge_queue.pop(people_queue);

    while(!people_queue.empty())
      cout << setw(35) << x.name << setw(15) << x.age << endl;
  }
  return 0;
}
