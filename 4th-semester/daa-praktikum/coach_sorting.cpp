#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std; 
void introsort_r(string a, int first, int last, int depth);
void _introsort(string a, int n);
int _partition(string s, int first, int last);
void _insertion(string a, int n);
void _swap(char *a, char *b);
void _doheap(string a, int begin, int end);
void _heapsort(string a, int begin, int end);
bool _isSorted(string a, int end);

int get_num(char c){
  if(c >= 'A' && c <= 'Z'){
    return 37 + (c - 'A');
  }else if(c >= 'a' && c <= 'z'){
    return 11 + (c - 'a');
  }else if(c >= '0' && c <= '9'){
    return 1 + (c - '0');
  }
}

void introsort_r(string a, int first, int last, int depth){
  while(last - first > 0 ) {
    if(depth=0)
      _heapsort(&a[first], first,  last-first+1 );
    else {
      int pivot;
      if(_isSorted(a, last))
        break;
      pivot = _partition(a, first, last);
      introsort_r(a, pivot+1, last, depth-1);
      last = pivot -1;
    }
  }
}
 
void _introsort(string a, int n){
  introsort_r ( a, 0, n-1, (int(2*log(double(n)))));
  _insertion(a, n);
}
 
int _partition (string a, int first, int last){
  int pivot, mid = (first+last)/2;
 
  pivot = get_num(a[first]) > get_num(a[mid])  ? first : mid;
 
  if(get_num(a[pivot]) > get_num(a[last]))
    pivot = last;
 
  _swap( &a[pivot], &a[first] );
  pivot = first;
 
  while ( first < last ){
    if ( get_num(a[first]) <= get_num(a[last]) )
      _swap( &a[pivot++], &a[first] );
    ++first;
  }
 
  _swap (&a[pivot], &a[last]);
  return pivot;
}
 
void _insertion (string a, int n) {
  int i;
  for ( i = 1; i < n; i++ ) {
    int j, save = a[i];
    for ( j = i; j >= 1 && get_num(a[j - 1]) > get_num(save); j-- )
      a[j] = a[j - 1];
    a[j] = save;
  }
}
 
void _swap(char *a, char *b){
  char save = *a;
  *a = *b;
  *b = save;
}

void _doheap(string a, int begin, int end ){
  char save = a[begin];
  while (begin <= end /2) {
    int k = 2* begin;
    while ( k < end && get_num(a[k]) < get_num(a[k+1]))
      ++k;
    if( get_num(save) >= get_num(a[k]))
      break;
    a[begin] = a[k];
    begin = k;
  }
  a[begin] = save;
}
 
void _heapsort(string a, int begin, int end ){
  int i;
  for(int i = (end-1) / 2; i >= begin; i--){
    _doheap( a, i , end-1);
  }
  for( i=end-1; i>begin; i --){
    _swap( &a[i], &a[begin]);
    _doheap(a, begin, i-1);
    }
}

bool _isSorted(string a, int end){
  for(int i=0; i < end; i++){
    if(get_num(a[i]) > get_num(a[i+1])){
      return false;
    } else {
      return true;
    }
  }
  return true;
}

int main(){
  int n;
  
  scanf("%d", &n);
  string str, str2;
  cin >> str;
  
  _introsort(str, n);

  cout << str << endl;
}