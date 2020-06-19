#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> cnt(22);

	for(long long i : a) {
		for(int j = 0; j < 22; ++j) {
			if(i >> j & 1) {
				cnt[j] += 1;
			}
		}
	}

	long long ans = 0;

	for(int i = 0; i < n; ++i) {
		long long x = 0;
		for(int j = 21; j >= 0; --j) {
			if(cnt[j] > 0) {
				x += (1 << j);
				cnt[j] -= 1;
			}
		}
		ans += x * x;
	}

	cout << ans << '\n';

	return 0;
}
