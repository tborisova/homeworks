#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int main(){
  long k, a, counter;
  int n, j;
  long numbers[MAX_N];
  
  scanf("%d %ld", &n, &k);

  counter = n;
  for(int i = 0; i < n; i++){
    scanf("%ld", &numbers[i]);
  }

  sort(numbers, numbers + n);

  long *pointer;
  int l, index, index1;

  for(l = n; l >= 0; l--){
    pointer = lower_bound(numbers, numbers + n, numbers[l]/k);

    if(*pointer == numbers[l]/k){
      index = pointer - numbers;
      break;
    }
  }

  for(l = 0; l < n; l++){
    pointer = lower_bound(numbers, numbers + n, numbers[l]*k);

    if(*pointer == numbers[l]*k){
      index1 = l;
      break;
    }
  }

  for(int i = index1; i < index + 1; i++){
    pointer = lower_bound(numbers, numbers + n, numbers[i]*k);

    if(*pointer == numbers[i]*k){
      counter--;
    }
  }

  printf("%ld\n", counter);
}