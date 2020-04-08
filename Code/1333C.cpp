#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a(n + 5);

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	map<long long, int> mp;

	mp[0] = 1;

	long long sum = 0;

	long long ans = 0;

	for(int i = 1, j = 1; i <= n; ++i) {
		sum += a[i];

		int l = mp[sum];

		j = max(j, l + 1);

		ans += i - j + 1;

		mp[sum] = i + 1;
	}

	cout << ans << '\n';

	return 0;
}
