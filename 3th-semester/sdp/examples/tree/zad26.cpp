#include <iostream>
#include <cassert>
using namespace std;
#include "tree.cpp"
#include "depth.cpp"

typedef tree<int> intTree;

int main(){
  intTree t;

  t.create();
  t.print();

  int x = t.rootTree();
  cout << "root: " << x << endl;
  intTree t1 = t.leftTree(), t2 = t.rightTree();
  cout << "leftTree: \n";
  t1.print();
  cout << "rightTree: \n";
  t2.print();

  cout << depth(t) << endl;
  return 0;
}