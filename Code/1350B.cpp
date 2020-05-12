#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;
		
		vector<int> s(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		vector<int> dp(n, 1);

		for(int i = 0; i < n; ++i) {
			for(int j = (i + 1) * 2; j <= n; j += i + 1) {
				if(s[j - 1] > s[i]) {
					dp[j - 1] = max(dp[j - 1], dp[i] + 1);
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}
