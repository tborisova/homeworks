#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
	int n = 0;
	long  start[10000];
	long  end[10000];

	long  start_event, end_event;
	int i = 0;

	while(scanf("%ld %ld", &start_event, &end_event) == 2){
		start[i] = start_event;
		end[i] = start_event + end_event;
		i++;
	}
	n = i;
	int max = 1;
	long *pointer;
	int old_max = 0;

	// sort(start, start + n);

	for(i = 0; i < n; i++){
		for(int j = i; j < n;){
		    pointer = find(start, start + n, end[j]);
			if(*pointer == end[j]){
				max++;
				j = pointer - start;
			}else{
				j++;
			}
		}

		if(old_max < max){
			old_max = max;
		}
		max = 1;
	}

	printf("%d\n", old_max);
}