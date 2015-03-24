#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct times_struct{
  int hour;
  int minutes;
  int seconds;
  int position;

  bool operator<(const times_struct&other) const{
    if(hour < other.hour){
      return true;
    }else if(hour == other.hour){
      if(minutes < other.minutes){
        return true;
      }else if(minutes == other.minutes){
        if(seconds < other.seconds){
          return true;
        }else if(seconds == other.seconds){
          if(position < other.position){
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main(){
  int n;
  scanf("%d", &n);
  int minutes, hour, seconds;
  times_struct times[1000];

  for(int i = 0; i < n; i++){
    scanf("%d:%d:%d", &hour, &minutes, &seconds);
    times[i].hour = hour;
    times[i].minutes = minutes;
    times[i].seconds = seconds;
    times[i].position = i + 1;
  }

  sort(times, times + n);
  
  for(int i = 0; i < n; i++){
    cout << times[i].position << endl;
  }

}