template <typename T>
void BFS(const T& a, graph<T> g, LList<T> l){
  queue<T> q;
  q.push(a);
  l.toEnd(a);

  while(!q.empty()){
    q.pop(x);
    cout << x << endl;
    elem_link1<T>* p = g.point(x);
    p = p->link;
    while(p){
      if(!member(p->inf, l)){
        q.push(p->inf);
        l.toEnd(p->inf);
      }

      p = p->link;
    }
  }
}

template <typename T>
void fullBFS(graph<T>& g){
  LList<T> v = g.vertexes(), l, h = v;
  while(!h.empty()){
    h.iterStart();
    elem_link1<T> *p = h.iter();
    BFS(p->inf, g, l);
    h = differenceSets(v, l);
  }
}