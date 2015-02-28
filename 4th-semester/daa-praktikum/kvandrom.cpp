#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int countOfDigits(int number){
  int count = 0;

  while(number != 0){
    count++;
    number = number/10;
  }

  return count;
}

int reverse(int n){
  int res = 0;
  int count = countOfDigits(n) - 1;
  
  while(n != 0){
    res += (n % 10)*pow(10, count);
    n = n / 10;
    count--;
  }

  return res;
}

bool palindrome(int number){
  return number == reverse(number);
}

bool kvandrom(long int number){
 double res = sqrt(number);

 if (palindrome(number) && (ceil(res) == floor(res))) return palindrome(ceil(res));
}

int main(){
  int counter = 0, a, b;
  long int!!! a i b
  scanf("%d", &a);
  scanf("%d", &b);

  while(a <= b){
    if(kvandrom(a)) counter++;
    a++;
  }

  cout << counter;
  // printf("%d", counter);
}