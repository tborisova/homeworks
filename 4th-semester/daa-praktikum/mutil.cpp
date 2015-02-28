#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  long int n;
  long int number;

  scanf("%ld", &n);

  long int i = 0;
  long int numbers[n];

  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }

  long int product;
  long int ost = 1000000007;

  for(int i = 0; i < n; i++){
    product = 1;
    
    for(int j = 0; j < n; j++){
      if(i != j){
        product *= numbers[j];
      }
    }

    printf("%ld ", product % ost);
  }

  printf("\n");
}