#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float max_time, t;
	float c;

	scanf("%f %f", &c, &max_time);

	int x = 0;

	while(true){
		x++;
		t = c*x*log2(x)*0.01;
		if(t > max_time){
			x--;
			break;
		}
	}
	cout << x << endl;
}