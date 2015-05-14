#include <iostream>
#include <cstdio>
using namespace std;


int main(){

    int n, number, product = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
      scanf("%d", &number);
      product += number;
    }

    printf("%d", product % 2);
}