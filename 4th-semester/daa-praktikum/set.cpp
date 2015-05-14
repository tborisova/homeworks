#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){

  int n, k;

  scanf("%d", &n);
  scanf("%d", &k);

  int numbers[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }

  int res  = n;

  for(int i = 0; i < n;i++){
    if(find(numbers, numbers + n, k*numbers[i]) != numbers + n){
      res--;
    }
  }

  printf("%d", res);
}