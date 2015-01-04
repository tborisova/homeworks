#include <iostream>
#include <cassert>
using namespace std;
#include "tree.cpp"

typedef tree<char> charTree;

charTree create_tree_form(){
  char ch;
  charTree t;

  cin >> ch;

  if(ch >= '0' && ch <= '9'){
    charTree t1;
    t.create3(ch, t1, t1);
  }else{
    charTree t1,t2;
    t1 = create_tree_form();
    cin >> ch;
    t2 = create_tree_form();
    t.create3(ch, t1, t2);
    cin >> ch;
  }

  return t;
} // or you could use create()

bool isForm(const charTree& t){
  if(t.empty()) return false;

  char ch = t.rootTree();

  if(ch >= '0' && ch <= '9'){
    return t.leftTree().empty() && t.rightTree().empty();
  }

  if(ch != '/' && ch != '+' && ch != '-' && ch != '*') return false;

  return isForm(t.leftTree()) && isForm(t.rightTree());
}

int arrExp(const charTree &t){
  if(t.empty()){
    return 0;
  }else{
    char ch = t.rootTree();
    if(ch >= '0' && ch <= '9') return (int)ch - (int)'0';
    switch(ch){
      case '+': return arrExp(t.leftTree()) + arrExp(t.rightTree());
      case '-': return arrExp(t.leftTree()) - arrExp(t.rightTree());
      case '*': return arrExp(t.leftTree()) * arrExp(t.rightTree());
      case '/': int denom = arrExp(t.rightTree());
        if(denom){
          return arrExp(t.leftTree()) / denom;
        }else{
          cout << "Error! Division by 0!" << endl;
          return 0;
        }
    }
  }
}

void printFormula(const charTree &t){
  if(t.empty()) return;

  char ch = t.rootTree();

  if(ch >= '0' && ch <= '9'){
    cout << ch;
  }else{
    cout << "(";
    printFormula(t.leftTree());
    cout << ch;
    printFormula(t.rightTree());
    cout << ")";
  }
}

int main(){
  charTree t;

  t.create();

  if(isForm(t)){
    printFormula(t);
    cout << endl << arrExp(t) << endl;
  }else{
    cout << "It is not a formula" << endl;
  }
}