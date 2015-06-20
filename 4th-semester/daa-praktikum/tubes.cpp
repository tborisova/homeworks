#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 10000

int main(){
  int tests, n;
  long k;
  long tubes[MAXN];

  scanf("%d", &tests);

  while(tests){
    scanf("%d %ld", &n, &k);

    for(int i = 0; i < n;  i++){
      scanf("%ld", &tubes[i]);
    }

    // sort(tubes, tubes + n);
    int min = *min_element(tubes, tubes + n);
    int max = *max_element(tubes, tubes + n);

    int mid = (min + max)/2;
    int counter = 0;

    while(1){
      counter = 0;
      for(int i = 0; i < n; i++){
        counter += (tubes[i]/mid);
      }
      if(counter < k){
        mid = mid - (k-counter);
      }else if(counter > k){
        mid = mid + (k+counter);
      }else{
        break;
      }      
    }
    cout << mid << endl;
    tests--;
  }
}