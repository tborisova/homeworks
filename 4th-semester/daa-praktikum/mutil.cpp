#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  long int n;
  long int number;

  scanf("%ld", &n);

  long int i = 0;
  long int numbers[n];
  long int product = 1;

  for(int i = 0; i < n; i++){
    scanf("%ld", &numbers[i]);
    product *= numbers[i];
  }

  long int ost = 1000000007;

  for(int i = 0; i < n; i++){
    printf("%ld", (product / numbers[i]) % ost);
    if(i != n - 1){
      printf(" ");
    }
  }
}