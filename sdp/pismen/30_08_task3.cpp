#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;
#include "cyclicList.cpp"
#include "queue_linked.cpp"

void printElem(cyclicList<float>& list, queue<int>& q){
  list.iterStart();
  elem_cyclic<float> *el = list.iter();
  int q_el, counter = 1;

  while(!q.empty()){
    q.pop(q_el);
    while(q_el != counter){
      el = list.iter();
      if(el == NULL){
        list.iterStart();
        el = list.iter();
      }
      counter++;
    }
    cout << el->inf << " ";
  }
}

int main(){
  cyclicList<float> list;

  for(float i = 1.5; i <= 10.5; i++){
    list.toEnd(i);
  }

  queue<int> q;
  q.push(2);
  q.push(5);
  q.push(8);
  q.push(12);
  q.push(17);
  q.push(24);

  printElem(list, q);

}
