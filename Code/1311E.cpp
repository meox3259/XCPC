#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		if(d > n * (n - 1) / 2) {
			cout << "NO" << '\n';
			continue;
		}
		int low = 0, D = 0;
		for(int i = 1; i <= n; ++i) {
			if((i & (i - 1)) == 0) {
				++D;
			}
			low += D - 1;
		}
		if(d < low) {
			cout << "NO" << '\n';
			continue;
		}
		vector<int> par;
		vector<int> cnt;
		vector<int> dep;
		vector<int> bad;
		par.resize(n);
		cnt.assign(n, 1);
		cnt[n - 1] = 0;
		bad.resize(n);
		dep.resize(n);
		iota(dep.begin(), dep.end(), 0);
		for(int i = 1; i < n; ++i) {
			par[i] = i - 1;
		}
		int cur = n * (n - 1) / 2;
		while(cur > d) {
			int u = -1;
			for(int i = 0; i < n; ++i) {
				if(bad[i] == 0 && cnt[i] == 0 && (u == -1 || dep[u] > dep[i])) {
					u = i;
				}
			}
			if(u == -1) {
				break;
			}
			int p = -1;
			for(int i = 0; i < n; ++i) {
				if(dep[u] - dep[i] == 2 && cnt[i] < 2) {
					p = i;
					break;
				}
			}
			if(p == -1) {
				bad[u] = 1;
				continue;
			}
			--cnt[par[u]];
			--dep[u];
			++cnt[p];
			par[u] = p;
			--cur;
		}
		if(cur != d) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for(int i = 1; i < n; ++i) {
				cout << par[i] + 1 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
