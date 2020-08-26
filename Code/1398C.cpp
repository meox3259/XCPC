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

		string s;
		cin >> s;

		vector<int> pre(n + 1);
		for(int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + s[i] - '0';
		}

		unordered_map<int, int> mp;

		long long ans = 0;
		for(int i = 0; i <= n; ++i) {
			ans += mp[pre[i] - i];
			mp[pre[i] - i] += 1;
		}

		cout << ans << '\n';
	}

	return 0;
}
