// #include <iostream>
// #include <cstdlib>
// #include <cassert>
// using namespace std;

template <typename T=int>
struct elem_link1{
  T inf;
  elem_link1<T>* link;
};

template <typename T=int>
class LList{
public:
  LList();
  ~LList();
  LList(const LList&);
  LList& operator=(const LList&);
  bool empty() const;
  void iterStart(elem_link1<T>* p=NULL);
  elem_link1<T>* iter();
  void toEnd(const T&);
  void insertAfter(elem_link1<T>*, const T&);
  void insertBefore(elem_link1<T>*, const T&);
  void deleteAfter(elem_link1<T>*, const T&);
  void deleteBefore(elem_link1<T>*, const T&);
  void deleteElem(elem_link1<T>*, T&);
  void print() const;
  int length() const;
  void concat(const LList&);
  void reverse();
  template <typename P> friend istream& operator>>(istream& stream, LList<P>& list);
  template <typename P> friend ostream& operator<<(ostream& stream, LList<P>& list);
private:
  elem_link1<T>* start, *end, *current;
  void copyList(const LList&);
  void deleteList();
};

template <typename T> LList<T>::LList(){
  start = end = NULL;
}

template <typename T> LList<T>::LList(const LList<T>& list){
  copyList(list);
}

template <typename T> LList<T>::~LList(){
  deleteList();
}

template <typename T>
LList<T>&  LList<T>::operator=(const LList<T>& list){
  if(this != &list){
    deleteList();
    copyList(list);
  }

  return *this;
}

template <typename T> void LList<T>::copyList(const LList<T>& list){
  start = end = current = NULL;
  elem_link1<T> *p = list.start;

  while(p){
    toEnd(p->inf);
    p = p->link;
  }
}

template <typename T> void LList<T>::deleteList(){
  elem_link1<T> *p;

  while(start){
    p = start;
    start = start->link;
    delete p;
  }
  end = NULL;
}

template <typename T> void LList<T>::iterStart(elem_link1<T> *p){
  if(p) current = p;
  else current = start;
}

template <typename T> elem_link1<T>* LList<T>::iter(){
  elem_link1<T> *p = current;
  if(current) current = current->link;
  return p;
}

template <typename T> void LList<T>::toEnd(const T& x){
  elem_link1<T> *p = end;
  end = new elem_link1<T>;
  end->inf = x;
  end->link = NULL;
  if(p){
    p->link = end;
  }else{
    start = end;
  }
}

template <typename T> void LList<T>::insertAfter(elem_link1<T>* p, const T& x){
  elem_link1<T> *new_element = new elem_link1<T>;
  assert(new_element != NULL);
  new_element->inf = x;
  new_element->link = p->link;
  if(p == end)
    end = new_element;
  p->link = new_element;
}

template <typename T> void LList<T>::insertBefore(elem_link1<T>* p, const T& x){
  insertAfter(p, p->inf);
  p->inf = x;
}

template <typename T> void LList<T>::deleteAfter(elem_link1<T>* p, const T& x){
  if(p->link == NULL){
    cout << "can't delete after end";
    exit(1);
  }else{
    elem_link1<T>* temp = p->link;
    x = temp->inf;
    p->link = temp->link;
    if(temp == end) end = p;
    delete temp;
  }
}

template <typename T> void LList<T>::deleteElem(elem_link1<T>* p, T& x){
  
  if(start == p){
    x = start->inf;
    if(start == end)
      start = end = NULL;
    else
      start = start->link;
    delete p;
  }else{
    elem_link1<T> *q = start;
    while(q->link != p) q = q->link;
    deleteAfter(q, x);
  }
}

template <typename T> void LList<T>::deleteBefore(elem_link1<T>* p, const T& x){
  if(p != start){
    elem_link1<T> *q = start;
    while(q->link != p) q = q->link;
    deleteElem(q,x);
  } else{
    cout << "there is not element before start" << endl;
    exit(1);
  }
}

template <typename T> bool LList<T>::empty() const{
  return start == NULL;
}

template <typename T> void LList<T>::print() const{
  elem_link1<T> *temp = start;

  while(temp){
    cout << temp->inf << " ";
    temp = temp->link;
  }
  cout << endl;
}

template <typename T> int LList<T>::length() const{
  elem_link1<T> *temp = start;
  int n = 0;

  while(temp){
    temp = temp->link;
    n++;
  }

  return n;
}


template <typename T> void LList<T>::concat(const LList<T>& list){
  elem_link1<T> *temp = list.start;

  while(temp){
    toEnd(temp->inf);
    temp = temp->link;
  }
}

template <typename T> void LList<T>::reverse(){
  LList<T> r;
  iterStart();
  elem_link1<T> *p = iter();
  if(p){
    r.toEnd(p->inf);
    p = p->link;
    while(p){
      r.insertBefore(r.start, p->inf);
      p = p->link;
    }
  }
  *this = r;
}

template <typename T> ostream& operator<<(ostream& stream, LList<T>& list){
  list.iterStart();
  elem_link1<T>* el = list.iter();

  while(el){
    stream << el->inf << " ";
    el = list.iter();
  }
  stream << endl;
  return stream;
}


template <typename T> istream& operator>>(istream& stream, LList<T>& list){
  char ch = 'y';
  T x;

  while(ch == 'y'){
    cout << "Enter el: ";
    cin >> x;
    list.toEnd(x);
    cout << "Continue?(y/n): ";
    cin >> ch;
  }  
  
  return stream;
}

// int main(){
//   LList<int> l1, l2;

//   l1.toEnd(1);
//   l1.toEnd(3);
//   l1.toEnd(2);
//   l1.toEnd(3);
//   l1.toEnd(1);
//   cout << l1;

//   cin >> l2;
//   cout << l2;

// }