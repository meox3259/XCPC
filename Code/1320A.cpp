#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<int, long long> mp;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		mp[x - i] += x;
	}
	long long ans = 0;
	for(auto x : mp) {
		ans = max(ans, x.second);
	}
	cout << ans << '\n';
	return 0;
}
