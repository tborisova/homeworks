#include <iostream>
#include <cstdio>
using namespace std;

int main(){

  int n = 200, i = 2, j;

  char sieve[1000000];

  while(i <= n){
    if(sieve[i] == 0){
      printf("%5d", i);
    }
    j = i;
    while(j<=n){
      sieve[j] = 1;
      j += i;
    }
    i++;
  }

}