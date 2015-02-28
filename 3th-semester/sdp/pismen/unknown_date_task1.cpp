#include <iostream>
using namespace std;
#include "list_one_link.cpp"

template <typename T>int count(T& a, LList<T>& l){
  elem_link1<T> *p;
  l.iterStart();
  p = l.iter();
  int counter = 0;
  while(p){
    if(p->inf == a) counter++;
    p = l.iter();
  }
}

template <typename T>void remove(T& a, LList<T>){
  elem_link1<T> *p;
  l.iterStart();
  p = l.iter();

  while(p){
    if(p->inf == a) deleteElem(p);
    p = l.iter();
  }
}

template <typename T>void hist(T& a, LList<T>& l){
  elem_link1<T> *p;
  l.iterStart();

  while(p){
    cout << p->inf << " is in list " << count(p->inf, l) << " times" << endl;
    remove(p->inf, l);
    p = l.iter();
  }
}


