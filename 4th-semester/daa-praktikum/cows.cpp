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
  int mid = (houses[houses_count-1] - houses[0]);
  int counter;
  while(1){
    counter = 0;
    cout << counter << " " << cows_count << " " << mid << endl;
    for(int i = 0, j = houses_count - 1; i < houses_count && j >=0 ; i++, j--){
      if(i != j && houses[j] - houses[i] == mid) counter+=2;
    }
    cout << " counter is " << counter <<endl;
    if(counter < cows_count){
      mid = mid - (cows_count-counter);
    }else if(counter > cows_count){
      mid = mid + (cows_count+counter);
    }else{
      break;
    }      
  }
  cout << mid << endl;
}