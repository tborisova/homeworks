#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int tests, k, n, expected_k;
  long tubes[10000], num, max;
  scanf("%d", &tests);

  while(tests != 0){

    scanf("%d %d", &n, &k);

    // scanf("%ld", &tubes[0]);
    // max = tubes[0];

    for(int i = 0; i < n; i++){
      scanf("%ld", &tubes[i]);
      // if(max < tubes[i]) max = tubes[i];
    }

    expected_k = 0;
    bool found = false;

    sort(tubes, tubes + n);
    max = tubes[0];
    max_i = 0;

    while(max > 0){
      found = false;

      for(int i = 0; i < n; i++){
        num = tubes[i];
        while(num > 0 && (num - max) >= 0 && expected_k < k){
          num -= max;
          expected_k++;
          in_here++;
        }
      }

      if(k == expected_k){
        found = true;
        break;
      }

      max_i--;
      expected_k = 0;  
    }

    if(found){
      printf("%ld\n", max);      
    }else{
      printf("0\n");
    }
    tests--;
  }
}