// #include <iostream>
// #include <cassert>
// #include <cstdlib>
// using namespace std;
// #include "cyclicList.cpp"

template <typename T>
T accumulate(T (*op)(T, T), T null_value, cyclicList<T>& list){
  T s = null_value;
  list.iterStart();
  elem_cyclic<T> *p = list.iter();

  while(p){
    s = op(s, p->inf);
    p = list.iter();
  }

  return s;
}

int my_int_func(int x, int y){
  return x+y;
}

// int main(){
//   cyclicList<int> l1;

//   l1.insert(1);
//   l1.insert(10);
//   l1.insert(3);

//   cout << accumulate(&my_int_func, 0, l1);
// }