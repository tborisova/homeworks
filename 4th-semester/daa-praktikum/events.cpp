
#include <iostream>
#include <string>
#include <cstdio>
<<<<<<< HEAD
#include <algorithm>
#include <map>
#include <vector>
=======
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>
>>>>>>> more solutions added
using namespace std;

struct date_struct{
  int day;
  int month;
  int year;
<<<<<<< HEAD
  int seconds;
  int hour;
  int minutes;
=======
  int hour;
  int minutes;
  int seconds;
>>>>>>> more solutions added
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
<<<<<<< HEAD
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
=======
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
                  }
                }
             }
           }
>>>>>>> more solutions added
        }
      }
    }
    return false;
  }
};

int main(){
  int n;
  scanf("%d", &n);
<<<<<<< HEAD
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
=======
  int day, month, year, minutes, hour, seconds;

  date_struct dss[200000];

  for(int i = 0; i < n; i++){
    scanf("%d:%d:%d %d.%d.%d", &hour, &minutes, &seconds, &day, &month, &year);
    dss[i].index = i + 1;
    dss[i].day = day;
    dss[i].month = month;
    dss[i].year = year;
    dss[i].minutes = minutes;
    dss[i].hour = hour;
    dss[i].seconds = seconds;
>>>>>>> more solutions added
  }

  sort(dss, dss + n);
  
<<<<<<< HEAD
  for(int i = 0; i < n; i++){
=======
  for(int i=0; i < n; i++){
>>>>>>> more solutions added
    cout << dss[i].index << endl;
  }

}