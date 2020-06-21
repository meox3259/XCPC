#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long ans = 0;

	map<int, long long> cnt;

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x] += 1;
		ans += x;
	}

	int q;
	cin >> q;

	while(q--) {
		int b, c;
		cin >> b >> c;
		ans -= cnt[b] * b;
		ans += cnt[b] * c;
		cnt[c] += cnt[b];
		cnt[b] = 0;
		cout << ans << '\n';
	}

	return 0;
}
