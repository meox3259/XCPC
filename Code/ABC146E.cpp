#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a;
	a.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	map<int, int> mp;
	long long ans = 0;
	++mp[0];
	for(int i = 1; i <= n; ++i) {
		a[i] = (a[i] + a[i - 1]) % k;
		int t = ((a[i] - i) % k + k) % k;
		if(i - k >= 0) {
			--mp[((a[i - k] - (i - k)) % k + k) % k];
		}
		ans += mp[t];
		++mp[t];
	}
	cout << ans << '\n';
	return 0;
}
