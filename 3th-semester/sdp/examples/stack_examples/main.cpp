#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>
#include "stack_connected.cpp"
using namespace std;

// stack_not_connected
// int main(){
//   stack<> st(3);
//   st.push(10);
//   st.push(20);
//   st.push(30);

//   stack<int> st1 = st, st2;
//   st2 = st1;
//   st2.print();
//   return 0;
// }

// page 46 - green book sdp
int t(char c){
  int p;
  switch(c){
    case '+':
    case '-': p = 2;break;
    case '*':
    case '/': p =1;break;
    case '^':p=0;break;
    default: p = -1;
  }

  return p;
} 
void translate(char* s, char *ns){
  stack<char> st;
  st.push('(');
  char x;

  int i = 0, j = -1, n = strlen(s);

  while(i < n){
    if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'){
      j++;
      ns[j] = s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')'){
      st.pop(x);
      while(x != '('){
        j++;
        ns[j] = x;
        st.pop(x);
      }
    } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
      st.pop(x);
      while(x != '(' && t(x) <= t(s[i])){
        j++;
        ns[j] = x;
        st.pop(x);
      }
      st.push(x);
      st.push(s[i]);
    }
    i++;
  }

  st.pop(x);
  while(x!='('){
    j++;
    ns[j] = x;
    st.pop(x);
  }
  j++;
  ns[j] = '\0';
}

int value(char *s){

  stack<int> st;
  int x, y, z;

  unsigned int i=0, n = strlen(s);

  while(i < n){
    if(s[i] >= '0' && s[i] <= '9'){
      st.push((int)s[i] - (int)'0');
    }else{
      if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
        st.pop(x);
        st.pop(y);
        switch (s[i]){
          case '+': z = x+y;break;
          case '-': z = x-y;break;
          case '/': z = x/y;break;
          case '*': z = x*y;break;
          case '^': z = (int)pow(x, y);break;
        }
        st.push(z);
      }
    }
    i++;
  }

  st.pop(z);
  return z;
}
  char res[200] = {'('};

char* convert(const char* expr){
  stack<char> st;
  char x, y;

  int n = strlen(expr), i = 0, j = 1;

  while(i < n){
    if(expr[i] >= '0' && expr[i] <= '9'){
      cout << "will push " << expr[i] << endl;
      st.push(expr[i]);
    }else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^'){
      st.pop(x);
      cout << "will pop x " << x << endl;
      if (st.empty()){
        res[j++] = expr[i];
        res[j++] = x;
        res[j++] = ')';
        return res;
      } else {
        res[j++] = '(';

        while(!st.empty()){
          st.pop(y);
          res[j++] = y;
          res[j++] = expr[i];
        }
        res[j++] = x;
        res[j++] = ')';
      }
    }
    i++;
  }
  return res;
}

int evaluate(const char* expr){

  stack<int> st;
  int n = strlen(expr), x, y, i = 0 ,j = 0, z;

  while(i < n){
    if(expr[i] >= '0' && expr[i] <= '9'){
      st.push((int)expr[i] - (int)'0');
    }else{
      st.pop(x);
      st.pop(y);
      switch(expr[i]){
        case '+': z = x+y;break;
        case '*': z = x*y;break;
        case '-': z = x-y;break;
        case '/': z = x/y;break;
        case '^': z = (int)pow(x,y);
      }
      st.push(z);
    }
    i++;
  }
  st.pop(z);
  return z;
}


int main(){
  char s[200] = {'1', '2', '2', '+', '8', '*'};
  // char ns[200];
  char *res;
  cout << evaluate(s) << endl;
  // translate(s, ns);
  res = convert(s);


  for (int i = 0; i < strlen(res); i++){
    cout << res[i];
  }
  cout << endl;
}

