#include <iostream>
#include <cstdlib>
using namespace std;
#include "queue.cpp"

int solution(char *str, queue<int>& q){
  stack<char> functions;
  stack<char> functions;
  char function;
  int len = strlen(str), i = 0, number;

  while(i < n){
    if(str[i] == ')'){
      functions.pop(function);
      numbers.pop(number);
      if(function == 's') numbers.push(q.s(number));
      else numbers.push(q.m(number));
    } // pop from functions stack // pop from numbers stack
    if(str[i] == 'm' || str[i] == 's'){
      functions.push(str[i]);
    } // push to functions stack
    if(str[i] >= '0' && str[i] <= '9'){
      numbers.push(str[i]);
    } //push to number stack
  }

  int result;
  numbers.pop(result);
  return result;
}

// char str[20]
