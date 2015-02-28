#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;
#include "stack_connected.cpp"

int main(){
  stack<char> st, st2;
  // char ch = 'c';
  char ch2;
  char line[30];

  cout << "enter something  ";
  cin.getline(line, sizeof(line));
  
  for(int i = 0; i < strlen(line); i++){
    if(line[i] == '*' && !st.empty()){
      st.pop(ch2);
    }else if(line[i] == '-'){
      while(!st.empty()) st.pop(ch2);
    }else{
      st.push(line[i]);
    }
  }  
  if(!st.empty()){
    st.print();
  }
}