#include <iostream>
using namespace std;
#include "stack.cpp"
#include "tree.cpp"


template <typename T> bool levelCheck(tree<T>& t, stack<T>& st, int level){
    //обхождане в ширина на дърво - като check_level и имаме брояч, когато той стане равно на level, почваме да поп-ваме от стека
  // и да гледаме дали елементите на нивото са като тези от стека
}

template <typename T> void levelTree(tree<T>& t, int level, stack<T> st){
  if(level == 0) {
    st.push(t.rootTree());
    return;
  }

  levelTree(t.leftTree(), level - 1, st);
  levelTree(t.rightTree(), level - 1, st);
}