#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int countOfDigits(long int number){
  int count = 0;

  while(number != 0){
    count++;
    number = number/10;
  }

  return count;
}

int reverse(long int n){
  long int res = 0;
  int count = countOfDigits(n) - 1;
  
  while(n != 0){
    res += (n % 10)*pow(10.00, count);
    n = n / 10;
    count--;
  }

  return res;
}

bool is_smaller(long int a, long int b){
  int digit_a, digit_b;

  while(a != 0 && b != 0){
    digit_a = a / pow(10.00, countOfDigits(a) - 1);
    digit_b = b / pow(10.00, countOfDigits(b) - 1);

    if(digit_a < digit_b) return true;
    if(digit_a > digit_b) return false;
    if(digit_a == digit_b){
      a = reverse(reverse(a) / 10);
      b = reverse(reverse(b) / 10);
    }
  }

  if(a == 0 && b != 0) return true;
  if(a != 0 && b == 0) return false;
}

int main(){
  int n, i, k, j;

  scanf("%d", &n);

  long int numbers[n];
  long int min;

  for(i = 0; i < n; i++){
    scanf("%ld", &numbers[i]);
  }

  for(i = 0; i < n - 1; i++){
    min = numbers[i];
    k = i;

    for(j = i + 1; j < n; j++){

      if(is_smaller(numbers[j], min)){
        min = numbers[j];
        k = j;
      }
    }

    numbers[k] = numbers[i];
    numbers[i] = min;
  }

  for(i = 0; i < n; i++){
    printf("%ld\n", numbers[i]);
  }
}
