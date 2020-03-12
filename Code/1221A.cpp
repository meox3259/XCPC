#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		vector<int> s;
		s.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		vector<int> dp;
		dp.resize(2049);
		dp[0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 2048; j >= s[i]; --j) {
				dp[j] |= dp[j - s[i]];
			}
		}
		if(dp[2048] == 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
