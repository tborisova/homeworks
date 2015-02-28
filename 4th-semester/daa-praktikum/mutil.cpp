#include <iostream>
using namespace std;

int main(){
  long int n;
  long int number;

  cin >> n;

  long int i = 0;
  long int numbers[n];

  while(cin >> number){
    numbers[i] = number;
    i++;
  }

  double product;

  for(int i = 0; i < n; i++){
    product = 1;
    
    for(int j = 0; j < n; j++){
      if(i != j){
        product *= numbers[i]*numbers[j]
      }
    }

  }
}