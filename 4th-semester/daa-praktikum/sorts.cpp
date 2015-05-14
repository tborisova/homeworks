#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	float max_time, t;
	float c;

	scanf("%f %f", &c, &max_time);

	int x = max_time;

	// cout << max_time / (c*0.01) << endl;
	// cout << 116 << " " << log2(116) << endl;
	// cout << (8*log2(8)*0.01) << endl;
	while(true){
		x++;
		t = c*x*log2(x)*0.01;
		if(t >= max_time){
			x--;
			break;
		}
	}
	cout << x << endl;
}