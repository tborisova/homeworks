#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n, m, a, b, index;
  int numbers[100000];
  int* pointer_a, *pointer_b;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }

  scanf("%d", &m);

  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    pointer_a = lower_bound(numbers, numbers + n, a);
    pointer_b = upper_bound(numbers, numbers + n, b);
    index = pointer_b - pointer_a;
    printf("%d\n", index);
  }  

}