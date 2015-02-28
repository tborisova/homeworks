// #include <iostream>
// #include <cassert>
// #include <cstdlib>
// using namespace std;
// #include "cyclicList.cpp"

template <typename T>
void filter(bool (*pred)(T), cyclicList<T>& list, cyclicList<T>& l2){
  list.iterStart();
  elem_cyclic<T> *p = list.iter();

  while(p){
    if(pred(p->inf)) l2.toEnd(p->inf);
    p = list.iter();
  }

  return;
}

bool my_int_func(int x){
  return x > 2;
}

// int main(){
//   cyclicList<int> l1;

//   l1.toEnd(1);
//   l1.toEnd(10);
//   l1.toEnd(3);
//   l1.print();
//   cyclicList<int> l2;
//   filter(&my_int_func, l1, l2);
//   l2.print();
// }