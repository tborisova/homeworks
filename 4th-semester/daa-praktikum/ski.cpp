#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int best_m, best_h, best_s;

bool is_faster(int m, int s, int h){
  if(m < best_m){
    return true;
  }else if(m == best_m){
    if(s < best_s){
      return true;
    }else if(s == best_s){
      return h < best_h;
    }
  }
  return false;
}

bool are_equal(int m, int s, int h){
  return m == best_m && s == best_s && h == best_h;
}

int main(){
  int n, m, s, h;
  string name;
  int count_of_people_with_score_equal_to_current_best_score = 1;
  int count_of_people_with_score_equal_to_previous_best_score = 0;
  scanf("%d", &n);
  cin >> name;
  scanf("%d:%d.%d", &best_m, &best_s, &best_h);
  cout << name << " " << 1 << endl;

  for(int i = 0; i < n - 1; i++){
    cin >> name;
    scanf("%d:%d.%d", &m, &s, &h);
    if(is_faster(m, s, h)){
      count_of_people_with_score_equal_to_previous_best_score = count_of_people_with_score_equal_to_current_best_score;
      count_of_people_with_score_equal_to_current_best_score = 0;
      cout << name << " " << 1 << endl;
      best_m = m; best_h = h; best_s = s;
    }else if(are_equal(m, s, h)){    
      cout << name << " " << count_of_people_with_score_equal_to_previous_best_score + 1 << endl;
      count_of_people_with_score_equal_to_current_best_score++;
    }else{
      cout << name << " " << count_of_people_with_score_equal_to_current_best_score + 1 << endl;
    }
  }
}