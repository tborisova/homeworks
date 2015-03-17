#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
  int n;

  scanf("%d", &n);

  int numbers[800000], index;

  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }
  sort(numbers, numbers + n);
  int power;
  int* pointer;

  scanf("%d", &power);

  while(power != 0){
    pointer = lower_bound(numbers, numbers + n, power);
    
    if(*pointer == power){      
      index = pointer - numbers;
      printf("%d\n", index);
    }else{
      printf("-1\n");
    }
    scanf("%d", &power);
  }

  return 0;
}