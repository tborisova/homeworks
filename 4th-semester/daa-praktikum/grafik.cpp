#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

struct event{
  long start;
  long duration;

  bool operator<(const event& other) const{
    return start < other.start;
  }

};

int main(){
  long n = 0;
  long start_event, end_event;
  long i = 0;
  event events[1000];

  while(scanf("%ld %ld", &start_event, &end_event) == 2){
    events[i].start = start_event;
    events[i].duration = end_event;
    i++;
  }

  n = i;
  long max = 0, k,j;
  long old_max = 0;
  sort(events, events + n);

  for(i = 0; i < n/2; i++){
    k = i;
    max = 1;
    for(j = i+1; j < n;j++){
               if(events[k].duration + events[k].start <= events[j].start){
                  max++;
                  k = j;
               }
    }

    if(old_max < max){
      old_max = max;
    }
  }

  printf("%ld\n", old_max);
}