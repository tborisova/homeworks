#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_HOUSES_COUNT 100000
#define MAX_COWS_COUNT 100000

int main(){
  int cows[MAX_COWS_COUNT];
  int houses[MAX_HOUSES_COUNT];
  int houses_count, cows_count;

  cin >> houses_count >> cows_count;

  for(int i = 0; i< houses_count;i++){
    cin >> houses[i];
  }

  sort(houses, houses + houses_count);

  int max_distance = 0;
  int mid_element = houses_count/cows_count;
  int left_element = houses[0];
  int rigth_element = houses[n-1];
  int to_lookup = max(mid_element - left_element, rigth_element - mid_element);

  int left = 0;
  int righ = n-1;

  // while(left <= righ){
  //   int mid = (left + righ)/2;

  //   if(mid )
  // }
  

  // new
  int parts = houses_count/cows_count;
  if(parts == 2){
    int left = 0;
    int righ = n -1;
    parts = 1;
  }else{
    int left = 0;
    int righ = parts;
  }

  for(int i = 0; i < parts; i++){
    int max_distance = 0;
  
    for(int i = 0, j = houses_count - 1; i < houses_count && j >= 0; i++, j--){
      if(houses[j] - houses[i] > max_distance && j != i){
        max_distance = houses[j] - houses[i];
      }
    }
    
    left = parts;
    righ += parts;
  }

  cout << max_distance << endl;
}