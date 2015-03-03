#include <iostream>
#include <cstdio>
using namespace std;

int main(){

  long int n, f;
  int students = 0;

  scanf("%ld", &n);
  scanf("%ld", &f);

  while(n > 0){
    students++;
    n -= (f+1);  
  }

  printf("%d", students);
}