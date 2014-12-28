#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "cyclicList.cpp"

typedef cyclicList<int> intCycl;

void create(int m, intCycl& l){

  for(int i=0;i<=m;i++){
    l.toEnd(i);
  }
}

void josiff(int n, intCycl l){
  l.iterStart();

  elem_cyclic<int> *p = l.iter(), *q;

  while(p != p->link){
    q = p;
    for(int i=1; i <= n -1;i++){
      q = q->link;
    }
    p = q->link;
    int x;
    l.deleteElem(q, x);
    cout << x << " ";
  }
  cout << p->inf << endl;
}

int main(){
  intCycl l;
  int n,m;

  cout << "m: ";cin >> m;
  create(m, l);
  l.print();
  cout << "n: ";cin>>n;
  josiff(n, l);
  return 0;
}