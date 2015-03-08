#include <iostream>
using namespace std;

int main(){
  int a = 150, b = 125,t;

  while(b > 0){
    t = a;
    a = b;
    b = t % a;
  }

  cout << a << endl;
}