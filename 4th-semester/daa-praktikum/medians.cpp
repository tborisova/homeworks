#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, a;

  scanf("%d", &n);
  int numbers[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }
  
  for(int i = 0; i < n; i++){
    for(int k = 2; k < i; k++){
      for(int j = k; j < 1 && numbers[j] < numbers[j+1]; k--){
        a = numbers[k];
        numbers[j] = numbers[k]; 
        numbers[k] = a;
      }
    }
    if(i % 2){
      printf("%.1f", (numbers[i/2] + numbers[(i/2) + 1])/2.0);
    }else{
      printf("%.1f", (float)numbers[i/2]);
    }
    if(i != n - 1){
      printf(" ");
    }
  }
}