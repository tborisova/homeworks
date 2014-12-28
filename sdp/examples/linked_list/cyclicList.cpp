template <typename T>
struct elem_cyclic{
  T inf;
  elem_cyclic<T>* link;
};

template <typename T>
class cyclicList{
public:
  cyclicList();
  ~cyclicList();
  cyclicList(const cyclicList&);
  cyclicList& operator=(const cyclicList&);
  bool empty() const;
  void iterStart(elem_cyclic<T>* p = NULL);
  elem_cyclic<T>* iter();
  void insert(const T&);
  void toEnd(const T&);
  void deleteElem(elem_cyclic<T>*, T&);
  void print() const;
  int length() const;
private:
  elem_cyclic<T> *start, *current;
  void copyList(const cyclicList&);
  void deleteList();
};

template<typename T> cyclicList<T>::cyclicList(){
  start = NULL;
}

template<typename T> cyclicList<T>::~cyclicList(){
  deleteList();
}

template<typename T> cyclicList<T>::cyclicList(const cyclicList& list){
  copyList(list);
}

template<typename T> cyclicList<T>& cyclicList<T>::operator=(const cyclicList& list){
  if(this != &list){
    deleteList();
    copyList(list);
  }

  return *this;
}

template <typename T> void cyclicList<T>::copyList(const cyclicList& list){
  start = NULL;

  elem_cyclic<T> *p = list.start;

  if(p){
    do{
      p = p->link;
      toEnd(p->inf);
    }while(p != list.start);
  }
}

template <typename T> void cyclicList<T>::deleteList(){
  iterStart();
  elem_cyclic<T> *p = iter();

  while(p){
    delete p;
    p = iter();
  }

  start = NULL;
}

template <typename T> bool cyclicList<T>::empty() const{
  return start == NULL;
}

template <typename T> void cyclicList<T>::iterStart(elem_cyclic<T> *p){
  if(p) current = p;
  else if(start){
    current = start->link;
  } else{
    current = NULL;
  }
}

template <typename T> elem_cyclic<T>* cyclicList<T>::iter(){
  if(current){
    elem_cyclic<T> *p = current;
    if(current == start) current = NULL;
    else current = current->link;
    return p;
  }else{
    return NULL;
  }
}

//adds element after the last element.The new element is first
template <typename T> void cyclicList<T>::insert(const T& x){
  elem_cyclic<T> *new_element = new elem_cyclic<T>;
  new_element->inf = x;
  if(start){
    new_element->link = start->link;
  }else{
    start = new_element;
  }

  start->link = new_element;  
}

//adds element at the end
template <typename T> void cyclicList<T>::toEnd(const T& x){
  insert(x);
  start = start->link;
}

template <typename T> void cyclicList<T>::deleteElem(elem_cyclic<T> *p, T& x){  
  x = p->inf;

  if(start != start->link){
    elem_cyclic<T> *q = start;
    while(q->link != p){
      q = q->link;
    };

    q->link = p->link;
    if(p == start) start = q;
  }else{
    start = NULL;
  }
  delete p;
}

template <typename T> void cyclicList<T>::print() const{
  if(!empty()){
    elem_cyclic<T> *p = start;
    if(p){
      do{
        cout << p->inf << " ";
        p = p->link;
      }while(p != start);
    }
    cout << endl;
  }
}

template <typename T> int cyclicList<T>::length() const{
  int n = 0;
  elem_cyclic<T> *p = start;
  if(p){
    do{
      p = p->link;
      n++;
    }while(p != start);
  }

  return n;
}

// int main(){

//   cyclicList<int> l1;

//   l1.insert(1);
//   l1.insert(3);
//   l1.insert(2);
//   l1.print();
// }