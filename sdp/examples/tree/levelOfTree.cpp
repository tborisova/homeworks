#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "tree.cpp"
#include "map.cpp"
#include "stack_connected.cpp"

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

void levelTree(tree<int> t, int level, stack<int>& st){
  if(t.empty()) return;
  if(level == 0) {
    st.push(t.rootTree());
  }else{
    levelTree(t.rightTree(), level - 1, st);
    levelTree(t.leftTree(), level - 1, st);
  }
}

int main(){
  intTree t;

  t.create();

  stack<int> st;
  levelTree(t, 2, st);
  st.print();
  return 0;
}