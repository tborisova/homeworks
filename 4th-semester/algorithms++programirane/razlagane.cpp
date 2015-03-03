#include <iostream>
#include <cstdio>

using namespace std;
int main(){
  int n = 520, i = 1, how;

  while(n != 1){
    i++;
    how = 0;

    while(n % i == 0){
      how++;
      n = n / i;
    }

    for(int j = 0; j < how; j++){
      printf("%d ", i);
    }
  }
  cout << endl;
}