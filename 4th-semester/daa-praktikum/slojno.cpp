#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, tests, current;
  int numbers[2048], posistions[2048];

  scanf("%d", &tests);

  while(tests > 0){
    current = 0;
    scanf("%d", &n);
    
    for(int i=0; i < n; i++){
      scanf("%d", &numbers[i]);
    }
    
    int *min_el = min_element(numbers, numbers + n);
    int min = *min_el;
    int end = n;
    int i;
    for(i = 0; i < n - 1 && numbers[i] <= numbers[i+1]; i++);

    if(i != n - 1){
      while(true){
          int posistion = distance(numbers, max_element(numbers, numbers + end));      
          if(posistion != 0){
            reverse(numbers, numbers + posistion + 1);
            posistions[current++] = posistion + 1;
          }
            reverse(numbers, numbers + end);
          
          if(numbers[0] == min && end != 0){
            break;
          }
          end--;
      }
    }

      printf("%d\n", current);
      if(current != 0){
      for(int i = 0; i < current; i++){
        printf("%d", posistions[i]);
        if(i != current - 1){
          printf(" ");
        }
      }
      printf("\n");
    }
      tests--;
  }
}