#include <iostream>
#include <cassert>
using namespace std;
#include "tree.cpp"
#include "accumulate.cpp"

typedef tree<int> intTree;

int sum(int x,int y){
  return x+y;
}

int po(int x, int y){
  return x*y;
}

int main(){
  intTree t;

  t.create();
  t.print();
  cout << accumulate(sum, 0, t) << endl;
  cout << accumulate(po, 1, t) << endl;

return 0;
}