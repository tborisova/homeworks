#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>
#include "stack_connected.cpp"
using namespace std;

bool boolFormula(char *s){
  stack<char> s1, s2;
  char c, x, y;
  int i = 0, n  = strlen(s);

  while(i < n){
    if (s[i] == '~' || s[i] == '*' || s[i] == '+'){
      s1.push(s[i]);
    } else if(s[i] == 't' || s[i] == 'f'){
      s2.push(s[i]);
    } else if(s[i] == ')'){
      s1.pop(c);
      switch(c){
        case '~':
          s2.pop(x);
          if(x == 't') x = 'f';
          s2.push(x);
          break;
        case '*':
          s2.pop(y);
          s2.pop(x);
          if(x == 't' && y == 't') x = 't';
          else x = 'f';
          s2.push(x);
          break;
        case '+':
          s2.pop(y);
          s2.pop(x);
          if(x == 't' || y == 't') x = 't';
          else x = 'f';
          s2.push(x);
          break;
      }
    }
    i++;
  }
  s2.pop(c);
  return c == 't';
}

int main(){
  char s[50];
  cout << "s:  ";
  cin >> s;
  cout << boolalpha << boolFormula(s) << endl;

  return 0;
}