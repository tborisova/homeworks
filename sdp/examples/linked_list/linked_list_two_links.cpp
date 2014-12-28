// #include <iostream>
// #include <cassert>
// #include <cstdlib>
// using namespace std;

template <typename T>
struct elem_link2{
  T inf;
  elem_link2<T> *next, *prev;
};

template <typename T>
class DLList{
public:
  DLList();
  ~DLList();
  DLList(const DLList&);
  DLList& operator=(const DLList&);
  bool empty();
  void iterStart(elem_link2<T> *p = NULL);
  void iterEnd(elem_link2<T> *p = NULL);
  elem_link2<T>* iterNext();
  elem_link2<T>* iterPrev();
  void toEnd(const T&);
  void toStart(const T&);
  void deleteElem(elem_link2<T>* p, T&);
  void print() const;
  void print_reverse() const;
  int length() const;
private:
  elem_link2<T> *start, *end, *current_start, *current_end;
  void copyList(const DLList&);
  void deleteList();
};

template <typename T> DLList<T>::DLList(){
  start = end = NULL;
}

template <typename T> DLList<T>::~DLList(){
  deleteList();
}

template <typename T> DLList<T>::DLList(const DLList& list){
  copyList(list);
}

template <typename T> DLList<T>& DLList<T>::operator=(const DLList& list){
  if(this != &list){
    deleteList();
    copyList(list);
  }
  
  return *this;
}

template <typename T> bool DLList<T>::empty(){
  return start == NULL;
}

template <typename T> void DLList<T>::iterStart(elem_link2<T> *p){
  if(p) current_start = p;
  else{
    current_start = start;
  }
}

template <typename T> void DLList<T>::iterEnd(elem_link2<T> *p){
  if(p) current_end = p;
  else{
    current_end = end;
  }
}

template <typename T> elem_link2<T>* DLList<T>::iterNext(){
  elem_link2<T> *res = current_start;

  if(current_start){
    current_start = current_start->next;
  }

  return res;
}


template <typename T> elem_link2<T>* DLList<T>::iterPrev(){
  elem_link2<T> *res = current_end;

  if(current_end){
    current_end = current_end->prev;
  }

  return res;
}

template <typename T> void DLList<T>::toEnd(const T& x){
  elem_link2<T> *p = end;

  end = new elem_link2<T>;
  assert(end != NULL);

  end->inf = x;
  end->next = NULL;
  if(p) p->next = end;
  else start = end;
  end->prev = p;
}

template <typename T> void DLList<T>::toStart(const T& x){
  elem_link2<T> *p = start;

  start = new elem_link2<T>;
  assert(start != NULL);

  start->inf = x;
  start->prev = NULL;
  if(p) p->prev = start;
  else end = start;
  start->next = p;
}

template <typename T> void DLList<T>::deleteElem(elem_link2<T>* p, T& x){
  x = p->inf;

  if(end == start){ // only one element
    start = end = NULL;
  }else{
    if(p == start){
      start = start->next;
      start->prev = NULL;
    }else if(p == end){
      end = end->prev;
      end->next = NULL;
    }else{
      p->next->prev = p->prev;
      p->prev->next = p->next;
    }
  }

  delete p;  
}

template <typename T> void DLList<T>::print() const{
  elem_link2<T> *p = start;

  while(p){
    cout << p->inf << " ";
    p = p->next;
  }

  cout << endl;
}

template <typename T> void DLList<T>::print_reverse() const{
  elem_link2<T> *p = end;

  while(p){
    cout << p->inf << " ";
    p = p->prev;
  }

  cout << endl;
}

template <typename T> int DLList<T>::length() const{
  elem_link2<T> *p = start;
  int n = 0;

  while(p){
    n++;
    p = p->next;

  }

  return n;
}

template <typename T> void DLList<T>::copyList(const DLList<T>& list){
  start = end = NULL;
  elem_link2<T> *p = list.start;

  while(p){
    toEnd(p->inf);
    p = p->next;
  }
}

template <typename T> void DLList<T>::deleteList(){
  elem_link2<T> *p = start;

  while(p){
    start = start->next;
    delete p;
    p = start;
  }

  end = NULL;
}


// int main(){
//   DLList<int> l1;

//   l1.toEnd(1);
//   l1.toStart(2);
//   l1.toEnd(3);

//   // l1.deleteElem();
//   l1.iterStart();

//   elem_link2<int> *p = l1.iterNext();

//   while(p->inf != 2){
//     p = l1.iterNext();
//   }
//   int x;
//   l1.deleteElem(p, x);
//   l1.print();
// }