#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a;
	vector<int> b;
	a.resize(n);
	b.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	map<pair<int, int>, int> cnt;
	for(int i = 0; i < n; ++i) {
		int x = a[i], y = b[i];
		for(int dx = -1; dx < 2; ++dx) {
			for(int dy = -1; dy < 2; ++dy) {
				++cnt[{x + dx, y + dy}];
			}
		}
	}
	vector<long long> ans;
	ans.resize(10);
	for(auto it : cnt) {
		auto x = it.first.first;
      	auto y = it.first.second;
		auto grid = it.second;
		if(x > 1 && x < h && y > 1 && y < w) {
			++ans[grid];
		}
	}
	ans[0] = 1LL * (h - 2) * (w - 2);
	for(int i = 1; i < 10; ++i) {
		ans[0] -= ans[i];
	}
	for(int i = 0; i < 10; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}
