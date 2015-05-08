#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN  10000

int main(){
  int n;

  scanf("%d", &n);
  int numbers[MAXN];

  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }

  int tmp, key, j;

  for(int i = 0; i < n; i++){
    key = numbers[i];
    j = i - 1;

    while(j >= 0 && numbers[j] > key){
      numbers[j + 1] = numbers[j];
      j = j - 1;
    }

    numbers[j+1] = key;

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