#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;
		
		cout << s[0];
		for(int i = 1; i < s.size(); i += 2) {
			cout << s[i];
		}
		cout << '\n';
	}

	return 0;
}
