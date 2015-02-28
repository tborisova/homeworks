#include <iostream>
#include <cassert>
using namespace std;
#include "tree.cpp"

typedef tree<int> intTree;

intTree addElem(int a, const intTree& t){
  intTree t1;

  if(!t.empty()){
    t1.create3(t.rootTree() + a, addElem(a, t.leftTree()), addElem(a, t.rightTree()));
  }

  return t1;
}

int main(){
  intTree t;

  t.create();
  t.print();

  cout << "Number: "; 
  int a;
  cin >> a;

  addElem(a, t).print();

  return 0;
}