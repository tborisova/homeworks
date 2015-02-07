template <typename T>
class queue{
private:
  queue_element<T> *front, *rear;
public:
  queue();
  ~queue();
  queue& operator=(const queue<T>&);
  queue(const queue<T>&);
  void InsertElem(const T&)
}

template<typename T> queue<T>::queue(){
  front = rear = NULL;
}

template <typename T> queue<T>::~queue(){
  deleteQueue();
}

template <typename T> queue<T>& queue<T>::operator=(const queue<T>& q){
  if(this != &q){
    deleteQueue();
    copyQueue(q);
  }
  return *this;
}

template <typename T> queue<T>::queue(const queue<T>& q){
  copyQueue(q);
}

template <typename T> void queue<T>::copyQueue(const queue<T>& q){
  rear = front = NULL;  
  queue_element<T> *el = q.front;

  while(el){
    InsertElem(el->inf);
    el = el->link;
  }
  
}

template <typename T> void queue<T>::deleteQueue(){
  T x;

  while(!q.empty()){
    pop(x)
  }
}

template <typename T> queue<T>::void InsertElem(const T& x){
  queue_element<T> *new_element = new queue_element<T>
  new_element->inf = x;
  new_element->link = NULL;
  
  if(rear) rear->link = new_element;
  else front = new_element;
  rear = new_element;
}

template <typename T> ostream& LList<T>::<<(ostream& out, const LList<T>& l){
  l.iterStart();

  elem_link1<T>* el = l.iter();
  while(el){
    cout << el << " ";
    el = l.iter();
  }
  out << endl;
  return out;
}

template <typename T> istream& LList<T>::<<(istream& in, const LList<T>& l){
  char choice = 'y';
  T x;

  while(choice != 'n'){
    cout << "enter element ";
    in >> x;
    l.toEnd(x);
    cout <<" continue? (y/n) ";
    in >> choice;
  }

  return in;
}



template <typename T> T accumulate(const LList<T>& l, T (*func)(T, T), T null_value){
  l.iterStart();
  T result = null_value;
  elem_link1<T> *el = l.iter();

  while(el){
    result = op(result, el->inf);
    el = l.iter();
  }

  return result;
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

template <typename T> void merge(cyclicList<T>& l1, cyclicList<T>& l2, cyclicList<T>& result){
  l1.iterStart();
  l2.iterStart();
  elem_cyclic<T> *el1 = l1.iter();
  elem_cyclic<T> *el2 = l2.iter();

  while(!l1.empty() && !l2.empty()){
    if(el1->inf < el2->inf){
      result.toEnd(el1->inf);
      el1 = l1.iter();
    }else{
      result.toEnd(el2->inf);
      el2 = l2.iter();
    }
  }

  if(!l1.empty()){
    while(el1){
      result.toEnd(el1->inf);
      el1 = l1.iter();
    }
  }
  
  if(!l2.empty()){
    while(el2){
      result.toEnd(el2->inf);
      el2 = l2.iter();
    }
  }
}

template <typename T> void copyList(DLList<T>& list){
  start = end = NULL;
  elem_link2<T> *p = list.start;

  while(p){
    toEnd(p->inf);
    p = p->next;
  }
}

template <typename T> void deleteList(){
  elem_link2<T> *p = end;

  while(p){
    end = end->prev;
    delete p;
    p = end;
  }

  start = NULL;
}

template <typename T> bool top(const T& x){
  
  queue<tree<T> *> trees;

  trees.push(t);

  while(!trees.empty()){
    tree<T> *current;
    trees.pop(t);
    if(!t.empty()){
      if(t.rootTree() == x) return true;
      trees.push(t.leftTree());
      trees.push(t.rightTree());  
    }
  }

  return false;
}

template <typename T> int depth(tree<T>& t){
  if(t.empty()) return 0;
  int n,m;

  n = depth(t.leftTree());
  m = depth(t.leftTree());
  if(n > m) return n+1;
  else m + 1;
}


template <typename T> LList<T>& graph<T>::vertexes(){
  LList<T> l;

  g.iterStart();
  elem_link1< LList<T> > *p = g.iter();
  while(p){
    p->inf.iterStart();
    elem_link1<T> *q = p->inf.iter();
    l.toEnd(q->inf);
    p = p->link;
  }

  return l;
}


template <typename T> bool isolated(const graph<T>& g, const T x){
  LList<T> l;

  g.iterStart();
  elem_link1< LList<T> > *p = g.iter();
  p->inf.iterStart();
  elem_link1<T> *q = p->inf.iter();
    

  return l;
}
