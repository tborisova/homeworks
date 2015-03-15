#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n;
  int m;
  int counter = 0;
  long num2, num3;
  long available_shoes[1048576] = {};
  long feet_looking_for_shoes[1048576] = {};

  scanf("%d", &n);
  scanf("%d", &m);

  scanf("%ld", &num2);
  for(int i = 0; i < n - 1; i++){
    scanf("%ld", &num3);
    if(num3 > num2) num2 = num3;
    available_shoes[num3]++;
  }

  for(int i = 0; i < m; i++){
    scanf("%ld", &feet_looking_for_shoes[i]);
  }

  for(int i = 0; i < m; i++){
    if(available_shoes[feet_looking_for_shoes[i]]){
      counter++;
      available_shoes[feet_looking_for_shoes[i]]--;
    }else{
      long k = feet_looking_for_shoes[i];
      while(available_shoes[k] == 0 && k <= num2) k++;
      if(available_shoes[k] >= 1){
        counter++;
        available_shoes[k]--; 
      }
    }
  }

  printf("%d", counter);
}