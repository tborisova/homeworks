#include <iostream>
#include <cstdlib>
using namespace std;
#include "BinOrdTree.cpp"

bool check_tree(BinOrdTree<char*> t){
  if(t.leftTree().empty() && t.rigthTree().empty()) return true;
  if(t.leftTree().empty() && !t.rigthTree().empty()) return false;
  if(!t.leftTree().empty() && t.rigthTree().empty()) return false;

  if(cmp(concat(t.leftTree().rootTree(), t.rigthTree().rootTree()), t.rootTree()) == 0){
    return check_tree(t.leftTree()) && check_tree(t.rigthTree());
  }
}