#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  long int n, prev, next, counter = 0, sum = 0;
  int i;

  cin >> n;
  cin >> prev;

  for(int i = 1; i < n; i++){
    cin >> next;
    if(prev == next){
      counter++;
    }else if(counter != 0){
      while(counter != 0){
        sum += counter;
        counter--;
      }
    }
    prev = next;  
  }

  if(counter != 0){
    while(counter != 0){
      sum += counter;
      counter--;
    }
  }

  printf("%ld", sum + n);
}
