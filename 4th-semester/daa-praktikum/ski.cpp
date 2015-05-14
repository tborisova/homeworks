#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//http://judge.openfmi.net:9280/timed_contest/open_contest?contest_id=71
struct person{
  string name;
  int minutes;
  int seconds;
  int hundreds;

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

  bool operator>(person& other){
    return !(*this<other);
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

  for (int i = 1 ; i <= n - 1; i++) {
    person p = people[i];
    int index = i;

    while(index > 0 && (people[index - 1] > p || people[index - 1] == p) ){
      people[index] = people[index - 1];
      index--;
    }
    people[index] = p;

    cout << people[index].name << " " << index + 1 << endl;
  }
}