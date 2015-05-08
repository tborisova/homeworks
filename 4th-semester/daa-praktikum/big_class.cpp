#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define N 100000

int main(){
  int n, m;
  int upper_bound = 0, count, number;
  string name;
  int numbers[N] = { 0 };
  string students[N];
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> name >> count;
    upper_bound += count;
    students[i] = name;
    numbers[number] = i;
  }

  while(m){
    cin >> number;
    while(students[numbers[number]].size() == 0){
      number++;
    }
    cout << students[numbers[number]] << endl;
    m--;
  }
}