#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
#include "linked_list_one_link.cpp"

template <typename T>
class queue : LList<T>{
public:
  queue();
  ~queue();
  queue& operator=(const queue&);
  queue(const queue&);
  bool empty();
  void pop(T&);
  void push(const T&);
  void head(T&);
  int length();
  void print();
};

template <typename T> queue<T>::queue() : LList<T>(){}
template <typename T> queue<T>::~queue(){}
template <typename T> queue<T>::queue(const queue& r) : LList<T>(r){}
template <typename T> queue<T>& queue<T>::operator=(const queue& r){
  LList<T>::operator=(r);
}

template <typename T> bool queue<T>::empty(){
  LList<T>::empty();
}

template <typename T> void queue<T>::print(){
  LList<T>::print();
}

template <typename T> int queue<T>::length(){
  LList<T>::length();
}

template <typename T> void queue<T>::pop(T& x){
  if(!empty()){
    LList<T>::iterStart();
    elem_link1<T>* p = LList<T>::iter();
    deleteElem(p, x);
  }else{
    cout << "can't pop from empty queue" << endl;
    exit(1);
  }
}

template <typename T> void queue<T>::head(T& x){
  if(!empty()){
    LList<T>::iterStart();
    elem_link1<T>* p = LList<T>::iter();
    x = p->inf;
  }else{
    cout << "can't pop from empty queue" << endl;
    exit(1);
  }
}

template <typename T> void queue<T>::push(const T& x){
  LList<T>::toEnd(x);
}

// int main(){
//   queue<int> st;
//   st.push(10);
//   st.push(20);
//   st.push(30);

//   queue<int> st1 = st, st2;
//   st2 = st1;
//   st.print();
//   st2.print();
//   cout << st.length() << endl;
//   return 0;
// }

