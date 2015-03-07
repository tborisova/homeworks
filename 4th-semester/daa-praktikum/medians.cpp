#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;

  scanf("%d", &n);
  int numbers[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &numbers[i]);
  }
  
  vector<int> nums(numbers, numbers + n);
  
  for(int i = 0; i < n; i++){
    sort(nums.begin(), nums.begin() + i);
    if(i % 2){
      printf("%.1f", (nums[i/2] + nums[(i/2) + 1])/2.0);
    }else{
      printf("%.1f", (float)nums[i/2]);
    }
    if(i != n - 1){
      printf(" ");
    }
  }
}