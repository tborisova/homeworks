template <typename T>
void DFS(const T& a, graph<T>& g, LList<T>& l){
  l.toEnd(a);
  cout << a << endl;

  elem_link1<T>* p = g.point(a);
  p = p->link;

  while(p){
    if(!member(p->inf, l)){
      DFS(p->inf, g, l);
    }
    p = p->link;
  }

}


template <typename T>
void fullBFS(graph<T>& g){
  LList<T> v = g.vertexes(), l, h = v;
  while(!h.empty()){
    h.iterStart();
    elem_link1<T> *p = h.iter();
    DFS(p->inf, g, l);
    h = differenceSets(v, l);
  }
}

template <typename T>
int sumOfVertices(Graph& g){
    LList<T> v = g.vertexes(), l, h = v;
    
    while(!h.empty()){
      h.iterStart();
      elem_link1<T> *p = h.iter();
      DFS(p->inf, g, l);
      h = differenceSets(v, l);
    }
}
