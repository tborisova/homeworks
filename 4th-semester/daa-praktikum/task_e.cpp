#include <iostream>
using namespace std;

int main(){
  int tests;

  scanf("%d", &tests);

  while(tests != 0){
    int n;

    scanf("%d", &n);

    long int numbers[n];

    for(int i = 0; i < n; i++){
      scanf("%d", &numbers[i]);
    }

    for(int i = 0; i < n; i++){
      for(int k = 2; k < n; k++){
        if(numbers[i] < numbers[k]){
          swap(?)
        }
      }
    }
    
  }
}