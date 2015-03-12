#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct date_struct{
  int day;
  int month;
  int year;
  int seconds;
  int hour;
  int minutes;
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
          if(hour < other.hour){
            return true;
          }else if(hour == other.hour){
            if(minutes < other.minutes){
              return true;
            }else if(minutes == other.minutes){
              if(seconds < other.seconds){
                return true;
              }else if(seconds == other.seconds){
                if(index < other.index){
                  return true;
                }else{
                  return false;
                }
              }
            }
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
  int day, month, year, hour, minutes, seconds;
  char token1, token2, token3, token4, token5;

  date_struct dss[200000];
  char date[20];

  for(int i = 0; i < n; i++){
    cin.getline(&date, 20)
    dss[i].index = i + 1;
    dss[i].hour = (int)date[0];
    dss[i].minutes = (int)date[2];
    dss[i].seconds = (int)date[4];
    dss[i].day = (int)date[6];
    dss[i].month = (int)date[8];
    dss[i].year = (int)date[10];

    cout << "date : " << dss[i].hour << " " << dss[i].minutes << " " << dss[i].seconds << " " << " " << dss[i].day << " " << dss[i].month << " " << dss[i].year << endl;
  }

  sort(dss, dss + n);
  
  for(int i = 0; i < n; i++){
    cout << dss[i].index << endl;
  }

}