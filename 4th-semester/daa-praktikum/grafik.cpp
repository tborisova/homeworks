#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

struct event{
	long start;
	long duration;

	bool operator<(event& other){
		return start < other.start;
	}

	bool operator<(event& other) const{
		return start < other.start;
	}

	bool operator<(const event& other) const{
		return start < other.start;
	}

};

int main(){
	int n = 0;
	long start_event, end_event;
	int i = 0;
	event events[10000];

	while(scanf("%ld %ld", &start_event, &end_event) == 2){
		events[i].start = start_event;
		events[i].duration = start_event + end_event;
		i++;
	}

	n = i;
	int max = 1;
	event *pointer;
	int old_max = 0;
	sort(events, events + n);

	for(i = 0; i < n/2; i++){
		for(int j = i; j < n;){
		    pointer = lower_bound(events, events + n, events[j]);
			if(*pointer.start == events[j].duration){
				max++;
				j = pointer - events;
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