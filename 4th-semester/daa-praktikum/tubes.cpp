#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
  int tests, k, n;
  long tubes[10000];
  scanf("%d", &tests);

  while(tests){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
      scanf("%ld", &tubes[i]);      
    }

    sort(tubes, tubes + n);

    long min = tubes[0];
    bool keep_looking = true;
    int count = 0;
    while(keep_looking){
      keep_looking = false;
      for(int i = 1; i < n; i++){
        if((tubes[i] % min) == 0){
          count
        }
      }
    }

    printf("%ld\n", min);    
    tests--;
  }
}