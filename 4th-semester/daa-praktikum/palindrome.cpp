#include <iostream>
using namespace std;

#define MAXN 100000

int main(){
	string s;
	int chars[27];
	int counts[27];
	char palindrome[MAXN];
	int new_count = 0;
	int i, string_size;

	cin >> s;

	string_size = s.size();

	for(int i = 0; i < 27; i++){
		chars[i] = counts[i] = 0;
	}

	for(i = 0; i < string_size; i++){
		chars[s[i] - 'a']++;
	}

	int k = 0, p = 0;

	for(i = 0; i < string_size; i++){
		if(chars[s[i] - 'a'] % 2 == 0 && counts[s[i] - 'a'] == 0){
			counts[s[i] - 'a'] = chars[s[i] - 'a']/2;
			// palindrome[p] = s[i];
			p++;
			k++;
		}
	}
	int old_counts = 0;

	if(k == 0){
		cout << "IMPOSSIBLE" << endl;
	}else{

		for(i = 0; i < k; i++){
			old_counts = counts[i];
			while(counts[i] != 0){
				cout << s['a' + i];
				counts[i]--;
			}
			counts[i] = old_counts;
		}


		for(i = k - 1; i >= 0; i--){
			while(counts[i]){
				cout << s['a' + i];
				counts[i]--;
			}
		}

		cout << endl;
	}

	return 0;
}