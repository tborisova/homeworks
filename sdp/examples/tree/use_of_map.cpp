#include <iostream>
#include <cassert>
using namespace std;
#include "tree.cpp"
#include "map.cpp"

typedef tree<int> intTree;

int add_one(int x){
  return x+1;
}

int factoriel(int x){
  int f = 1;

  for(int i = 2; i <= x; i++){
    f = f*i;
  }

  return f;
}

int main(){
  intTree t;

  t.create();
  t.print();

  map(add_one, t).print();

  map(factoriel, t).print();

  
  return 0;
}