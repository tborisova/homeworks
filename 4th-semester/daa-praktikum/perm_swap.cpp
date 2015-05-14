#include <iostream>
#include <cstdio>
using namespace std;

int counter = 0;

int merge(int a[], int l, int mid, int h){
  int n1 = mid - l;
  int n2 = h - (mid + 1);
  int inv_count = 0;
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
      inv_count += (n1 - i);
      a[k] = left[i];
      i++;
    }else{
      a[k] = rigth[j];
      j++;
    }
  }

  return inv_count;
}

int merge_sort(int a[], int l, int h){
  int mid, inversions = 0;
  if(l < h){
    mid = (l+h)/2;
    inversions = merge_sort(a, l, mid);
    inversions += merge_sort(a, mid+1, h);
    inversions += merge(a, l, mid, h);
  }

  return inversions;
}

int main(){
  int n;
  int a[2000000];

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);  
  }

  cout <<  merge_sort(a, 0, n - 1) << endl;
  return 0;
}