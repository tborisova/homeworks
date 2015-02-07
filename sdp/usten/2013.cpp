template <typename T> ostream& queue<T>::operator<<(ostream& out, const queue<T>& q){
  while(!q.empty())

  out << endl;
  return out;
}

void insertBefore(elem_link1<T>* p, const T& x){
  elem_link1<T>* new_elem = new elem_link1<T>;
  new_elem->inf = x;
  new_elem->link = NULL;
  if(p == start){
    end->link = new_elem;
    end = new_elem;  
  }else{
    elem_link1<T>* current = start;
    while(current->link != p) current = current->link;
    new_elem->link = current->link;
    current->link = new_elem;
  }
}

LList<T>& map((T)(*map_func)(T), LList<T>& l){
  LList<T>& res;
  l.iterStart();
  elem_link1<T>* p = l.iter();

  while(p){
    res.toEnd(map_func(p->inf));
    p = l.iter();
  }

  return res;
}