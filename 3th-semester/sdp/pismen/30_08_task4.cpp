#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;
#include "graph.cpp"
#include "linked_list_one_link.cpp"

void check_if_tree(graph<int> &g){

  LList<int> v = g.vertexes();
  v.iterStart();
  elem_link1<int>* el = v.iter();

  while(el){
    elem_link1<int>* vertex = g.point(a);
    int counter = 0;
    while(vertex->link){
      counter++;
      vertex = vertex->link;
    }
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
