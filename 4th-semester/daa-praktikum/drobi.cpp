#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;


int main(){

  int n;
  int fractions[10000];
  int index = 1;
  stringstream ss;
  string number;
  string all_numbers;
       
  scanf("%d", &n);

  for(int i = 1; i <= n - 1; i++){

    for(int j = i + 1; j <= n; j++){
      if(j % i || i == 1){
        ss << i << "/" << j << " ";
        ss >> number;
        index++;
        all_numbers += number + " ";
      }
    }
  }
 
  istringstream iss (all_numbers);
  for (int i=0; i<index; i++){
    cout << fractions[i] << "  "; 
    iss >> fractions[i];
  }
  
  // for (int i=0; i<index; i++){
  //   cout << fractions[i];
  // }

  // sort(fractions, fractions + index);

  cout << all_numbers << endl;
  return 0;
}