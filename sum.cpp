#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	long n;
	int m;
	int numbers[1000000];
	int sums[10];
	bool found;
	scanf("%ld %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &numbers[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &sums[i]);
	}

	sort(numbers, numbers + n);

	for(int k = 0; k < m; k++){
		found = false;
		for(int i = 0, j = n - 1; i < n && j >= 0;){
			if(numbers[i] + numbers[j] == sums[k] && i != j){
				found = true;
				break;
			}else if(numbers[i] + numbers[j] > sums[k]){
				j--;
			}else{
				i++;
			}
		}
		if(found){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
