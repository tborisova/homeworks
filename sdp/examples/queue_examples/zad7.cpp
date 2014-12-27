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
  people s, dummy = {"xxx", -1};
  pqueue q1;
  int i, n;

  cout << "First queue:\n n = ";
  cin >>n;

  for(i=0;i < n;i++){
    cout << "Name: ";
    cin.ignore();
    cin.getline(s.name, 32);
    cout << "Age: ";
    cin >> s.age;
    q1.push(s);
  }

  pqueue q2;

  cout << "Second queue:\n n = ";
  cin >>n;

  for(i=0;i < n;i++){
    cout << "Name: ";
    cin.ignore();
    cin.getline(s.name, 32);
    cout << "Age: ";
    cin >> s.age;
    q2.push(s);
  }
  pqueue p, q, r;
  sortQueue(q1, p);
  sortQueue(q2, q);
  r = merge(p, q, dummy);

  people x;
  while(!r.empty()){
    r.pop(x);
    cout << setw(35) << x.name << setw(15) << x.age << endl;
  }
  return 0;
}
