#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int ans = 0;
	vector<int> v;
	for(int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		h %= (a + b);
		if(h <= a && h > 0) {
			++ans;
		} else {
			if(h == 0) {
				h = a + b;
			}
			v.emplace_back((h - 1) / a);
		}
	}
	sort(v.begin(), v.end());
	int tmp = k;
	for(int i = 0; i < min((int)v.size(), k); ++i) {
		if(tmp >= v[i]) {
			++ans;
			tmp -= v[i];
		} else {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
