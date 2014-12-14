#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
#include "queue_array.cpp"

template <typename T>
void minqueue(queue<T> q, T& min, queue<T>& newq){
  cout << q.empty() << endl;
  T x;

  q.pop(min);

  while(!q.empty()){
    q.pop(x);
    if(x < min){
      newq.push(min);
      min = x;
    }else{
      newq.push(x);
    }
  }
}

template<typename T>
void sortQueue(queue<T> q, queue<T>& newq){
  cout << q.empty() << endl;

  while(!q.empty()){
    T min;

    queue<T> q1;

    minqueue(q, min, q1);
    cout << "here" << endl;
    cout << min << endl;
    newq.push(min);
    q = q1;
  }
}

int main(){
  
  queue<int> q;
  queue<int> newq;
  for(int i = 10; i >= 1; i--){
    q.push(i);
  }

  sortQueue(q, newq);
  newq.print();
}