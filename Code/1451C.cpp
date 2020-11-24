#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {	
		int n, k;
		cin >> n >> k;

		string a, b;
		cin >> a >> b;

		vector<int> ca(26);
		for(char c : a) {
			ca[c - 'a'] += 1;
		}

		vector<int> cb(26);
		for(char c : b) {
			cb[c - 'a'] += 1;
		}

		bool ok = true;
		for(int i = 0; i < 26; ++i) {
			if(abs(ca[i] - cb[i]) % k != 0) {
				ok = false;
			}
		}

		for(int i = 0; i < 25; ++i) {
			if(ca[i] < cb[i]) {
				ok = false;
			}	
			int d = ca[i] - cb[i];
			if(d % k != 0) {
				ok = false;
			}
			ca[i] -= d;
			ca[i + 1] += d;
		}

		if(ca != cb) {
			ok = false;
		}

		if(ok) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
