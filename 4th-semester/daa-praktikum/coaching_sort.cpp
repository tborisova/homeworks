#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
 
 int get_num(char c){
  if(c >= 'A' && c <= 'Z'){
    return 37 + (c - 'A');
  }else if(c >= 'a' && c <= 'z'){
    return 11 + (c - 'a');
  }else if(c >= '0' && c <= '9'){
    return 1 + (c - '0');
  }
}

void merge(string &a, const int low, const int mid, const int high){
    string b(a);
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    while((h<=mid)&&(j<=high)){
      if(get_num(a[h])<=get_num(a[j])){
          b[i]=a[h];
          h++;
      }
      else{
          b[i]=a[j];
          j++;
      }
      i++;
    }

    if(h>mid){
      for(k=j;k<=high;k++){
          b[i]=a[k];
          i++;
      }
    }
    else{
      for(k=h;k<=mid;k++){
          b[i]=a[k];
          i++;
      }
    }

    for(k=0;k<=high-low;k++)
        a[k+low]=b[k];
   
}
 
void merge_sort(string &a, const int low, const int high){
  int mid;
  if(low < high){
    mid = ( low + high ) / 2;
    merge_sort( a, low, mid );
    merge_sort( a, mid + 1, high );
    merge( a, low, mid, high ); 
  }
}
 


int main(){
  int n;
  
  scanf("%d", &n);
  string str, str2;
  cin >> str;
  
  merge_sort(str, 0, n-1);

  cout << str << endl;
}