#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int tests, k, n, expected_k;
  long tubes[10000], num, min;
  scanf("%d", &tests);

  while(tests != 0){

    scanf("%d %d", &n, &k);

    scanf("%ld", &tubes[0]);
    min = tubes[0];

    for(int i = 1; i < n; i++){
      scanf("%ld", &tubes[i]);
      if(min > tubes[i]) min = tubes[i];
    }

    expected_k = 0;
    bool found = false;
    while(min > 0){
      found = false;

      for(int i = 0; i < n; i++){
        num = tubes[i];
        while(num > 0 && (num - min) >= 0 && expected_k < k){
          num -= min;
          expected_k++;
        }
      }

      if(k == expected_k){
        found = true;
        break;
      }

      min--;
      expected_k = 0;  
    }

    // if(min < 0){
    //   printf("0\n");
    // }else{
    if(found){
      printf("%ld\n", min);      
    }else{
      printf("0\n");
    }
    tests--;
  }
}