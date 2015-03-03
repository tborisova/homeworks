#include <stdio.h>
#include <math.h>

int main(){
  double digits = 0;

  long int n = 823;

  for(int i = 1; i <= n; i++){
    digits += log10(i);
  }
}