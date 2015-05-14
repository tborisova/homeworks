#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct student
{
  int fn;
  float score;
  int seat;
};

bool comparator_by_seat(const student one,const student two){
  return one.seat < two.seat;
}

bool comparator_by_score(const student one, const student two){
  if(one.score == two.score){
    return one.fn > two.fn;
  }else{
    return one.score > two.score;
  }
}

int main(){

  int n;

  student students[100000];

  scanf("%d", &n);

  for(int i = 0; i< n;i++){
    scanf("%d %d %f", &students[i].fn, &students[i].seat, &students[i].score);
  }

  stable_sort(students, students + n, comparator_by_seat);

  int k = students[n/2].seat;
  int b = students[n - 1].seat;
  float num;

  for(int i = 0; i< n;i++){
    if(students[i].score >= 3 && students[i].score < 6.00){
      num = fabs(k - students[i].seat);
      students[i].score = students[i].score + num/b;
      if(students[i].score > 6.00) students[i].score = 6.00;
    }
  }

  stable_sort(students, students + n, comparator_by_score);

  for(int i = 0; i< n;i++){
    printf("%d %.2f\n", students[i].fn, students[i].score);
  }

}
