#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct person{
  string name;
  int minutes;
  int seconds;
  int hundreds;
  int position;

  bool operator<(person& other){
   if(minutes < other.minutes){
      return true;
    }else if(minutes == other.minutes){
      if(seconds < other.seconds){
        return true;
      }else if(seconds == other.seconds){
        return hundreds < other.hundreds;
      }
    }
    return false; 
  }

  bool operator==(person& other){
   return minutes == other.minutes && seconds == other.seconds && hundreds == other.hundreds;
  }
};

int main(){
  int n, m, s, h, d, pos = 0;
  string name;
  person people[1000];
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    cin >> people[i].name;
    scanf("%d:%d.%d", &people[i].minutes, &people[i].seconds, &people[i].hundreds);
  }
  
  cout << people[0].name << " " << 1 << endl;
  people[0].position = 1;

  for (int c = 1 ; c <= n - 1; c++) {
    d = c;
    name = people[c].name;
    if(people[c] == people[d-1]){
      cout << people[d].name << " " << people[d-1].position << endl;
    }else{
      while ( d > 0 && people[d] < people[d-1]) {
        person t          = people[d];
        people[d]   = people[d-1];
        people[d-1] = t;
        d--;
      }
      if(people[d] == people[d - 1]){
        cout << people[d].name << " " << people[d-1].position << endl;
      }else{
        people[d].position = d + 1;
        cout << people[d].name << " " << people[d].position << endl;
      }
    }
  }

}