#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "queue_linked.cpp"

int main(){
  queue<int> q;
  for(int i = 1; i <= 10; i++){
    q.push(i);
  }
  q.print();
  // queue<char> p();
  // for(char c = 'a'; c <= 'z'; c++){
  //   p.push(c);
  // }
  // p.print();
  return 0;
}