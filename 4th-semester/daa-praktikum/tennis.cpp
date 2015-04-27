#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

int main(){
	map<string, int> players;
	int n, k, i, j = 0, len;
	char s[51];
	char name[21], other_player[21];
	char won_or_lost[5], over[5];

	scanf("%d %d", &n, &k);

	while(cin >> name >> won_or_lost >> over >> other_player){
		if(strcmp(won_or_lost, "won") == 0){
			players[name]++;
		}else{
			players[other_player]++;
		}
	}

	map<string,int>::iterator it = players.begin();
	
	while(it != players.end()){
		if(it->second == k){
			cout << it->first << endl;
		}
		it++;
	}

}