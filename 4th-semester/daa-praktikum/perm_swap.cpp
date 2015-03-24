#include <iostream>
using namespace std;

int counter = 0;

void merge(int a[], int l, int mid, int h){
  int n1 = mid - l;
  int n2 = h - (mid + 1);

  int left[n1 + 1];
  int rigth[n2 + 1];

  for(int i = 0, k = l; k <= mid; k++, i++){
    left[i] = a[k];
  }

  for(int i = 0, k = mid + 1; k <= h; k++, i++){
    rigth[i] = a[k];
  }

  left[n1 + 1] = 2000001;
  rigth[n2 + 1] = 2000001;
  int i = 0, j = 0;

  for(int k = l; k <= h; k++){
    if(left[i] <= rigth[j]){
      a[k] = left[i];
      i++;
    }else{
      a[k] = rigth[j];
      j++;
    }
  }
}

void merge_sort(int a[], int l, int h){
  int mid;
  if(l < h){
    mid = (l+h)/2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, h);
    merge(a, l, mid, h);
  }
}

int main(){
  int n;
  int a[2000000];

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);  
  }

  merge_sort(a, 0, n - 1);
cout << counter;
  return 0;
}