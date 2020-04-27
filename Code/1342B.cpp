#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		string t;
		cin >> t;

		bool ok = true;

		for(char c : t) {
			if(c != t[0]) {
				ok = false;
			}
		} 

		if(ok) {
			cout << t << '\n';
		} else {
			int n = t.size();

			for(int i = 0; i < 2 * n; ++i) {
				if(i & 1) {
					cout << '1';
				} else {
					cout << '0';
				}
			}

			cout << '\n';
		}
	}

	return 0;
}
