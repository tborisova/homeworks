// page 67 - green

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "queue_linked.cpp"

typedef queue<int> intQueue;
typedef queue<intQueue> queueQueue;

// template<typename T>
void queue<intQueue>::print(){
  intQueue x;

  while(!empty()){
    pop(x);
    x.print();
  }
  cout << endl;
}

int main(){

  queueQueue qq;

  for(int i=0; i <= 5; i++){
    intQueue q;

    for(int j=i; j <= 2*i;j++)
      q.push(j);
    qq.push(q);
  }

  for(int i=0; i <= 5; i++){
    intQueue q;

    for(int j=i; j <= 2*i;j++)
      q.push(j);
    qq.push(q);
  }
  
  qq.print();
  return 0;
}