#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, a, counter = 0, temp, el1_i, el2_i, tests;

  scanf("%d", &tests);

  while(tests != 0){
    scanf("%d", &n);

    int numbers[n], position_to_be_changed;

    for(int i=0; i < n; i++){
      scanf("%d", &numbers[i]);
    }

    int *min_el = min_element(numbers, numbers + n);
    int min = *min_el;
    int end = n;

    while(true){
        int posistion = distance(numbers, max_element(numbers + 1, numbers + end));      
        reverse(numbers, numbers + posistion + 1);
        cout << posistion + 1 << " ";
        if(posistion + 1 == end){
          end--;
        }
        reverse(numbers, numbers + end);
        if(numbers[0] != min){
          cout << end << " ";
        }else{
          cout << end;
          break;
        }
        end--;
      }
      cout << endl;
      tests--;
  }
}