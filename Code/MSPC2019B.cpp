#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt = 15;
	for(auto c : s) {
		if(c == 'x') {
			--cnt;
		}
	}
	if(cnt < 8) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
	return 0;
}

