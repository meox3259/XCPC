#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for(int j = 0; j < 26; ++j) {
		vector<int> b = a;
		for(int i = 0; i < n; ++i) {
			b[i] &= (1 << j + 1) - 1;
		}
		sort(b.begin(), b.end());
		int f = 0;
		for(int i = 0; i < n; ++i) {
			int l = lower_bound(b.begin(), b.begin() + i, (1 << j) - b[i]) - b.begin();
			int r = lower_bound(b.begin(), b.begin() + i, (1 << j + 1) - b[i]) - b.begin();
			f ^= r - l;
			l = lower_bound(b.begin(), b.begin() + i, 3 * (1 << j) - b[i]) - b.begin();
			r = lower_bound(b.begin(), b.begin() + i, (1 << j + 2) - b[i] - 1) - b.begin();
			f ^= r - l;
		}
		if(f & 1) {
			ans += 1 << j;
		}
	}
	cout << ans << '\n';
	return 0;
}
