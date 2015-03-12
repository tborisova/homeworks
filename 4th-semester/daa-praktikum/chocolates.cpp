#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct date_struct{
  string day;
  string month;
  string year;
  int index;

  bool operator<(const date_struct&other) const{
    if(year < other.year){
      return true;
    }else if(year == other.year){
      if(month < other.month){
        return true;
      }else if(month == other.month){
        if(day < other.day){
          return true;
        }else if(day == other.day){
          if(index < other.index){
            return true;
          }else{
            return false;
          }
        }
      }
    }
    return false;
  }
};

void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int main(){
  int n;
  scanf("%d", &n);

  date_struct dss[100];

  for(int i=0; i < n; i++){

    vector<string> v;
    v.reserve(3);
    string date;

    cin >> date;
    split(date, '.', v);
    dss[i].index = i + 1;
    dss[i].day = v[0];
    dss[i].month = v[1];
    dss[i].year = v[2];
  }

  sort(dss, dss + n);
  
  for(int i=0; i < n; i++){
    cout << dss[i].index << endl;
  }

}