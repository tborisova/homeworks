#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

int main(){
  int n, number;
  char command;
  priority_queue<int, vector<int>, less<int> > heap_container;
  
  scanf("%c", &command);

  while(command != 'Q'){
    if(command == 'A'){
      scanf("%d", &number);
      heap_container.push(number);
    }else if(command == 'L'){
      if(heap_container.empty()){
        printf("Not available\n");
      }else{
        printf("%d\n", heap_container.top());
      }
    }
    else if(command == 'R'){
      if(heap_container.empty()){
        printf("Not available\n");
      }else{
        printf("%d\n", heap_container.top());
        heap_container.pop();
      }
    }
    scanf("%c", &command);
  }
}