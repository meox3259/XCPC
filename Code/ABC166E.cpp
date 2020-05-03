#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int &i : a) {
		cin >> i;
	}

	map<int, int> mp;

	long long ans = 0;

	for(int i = 0; i < n; ++i) {
		ans += mp[i - a[i]];
		++mp[i + a[i]];
	}

	cout << ans << '\n';

	return 0;
}
