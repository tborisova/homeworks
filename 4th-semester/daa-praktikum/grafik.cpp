#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int n = 0;
	long start_event, end_event;
	int i = 0;
	map<long, long> events;

	while(scanf("%ld %ld", &start_event, &end_event) == 2){
		events[start_event] = end_event + start_event;
	}
	map<long, long>::iterator it, founded, it2;
	int max = 1;
	int old_max = 1;

	for(it=events.begin(); it!=events.end();it++){
		
		for(it2 = it; it2 != events.end();)	{

			founded = events.find(it2->second);

			if(founded != events.end()){
				it2 = founded;
				max++;
			}else{
				it2++;
			}	
		}

		if(old_max < max){
			old_max = max;
		}

		max = 1;
	}
	
	printf("%d\n", old_max);
}