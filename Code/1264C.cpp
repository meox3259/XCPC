#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int power(int x, int t) {
	int ret = 1;
	for(; t; t >>= 1, x = 1LL * x * x % P) {
		if(t & 1) {
			ret = 1LL * ret * x % P;
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> p(n), sumsuf(n + 1), suf(n + 1), invsuf(n + 1);
	int inv = power(100, P - 2);
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i] = 1LL * p[i] * inv % P;
	}
	suf[n] = 1;
	for(int i = n - 1; ~i; --i) {
		suf[i] = 1LL * suf[i + 1] * p[i] % P;
	}
	for(int i = 0; i <= n; ++i) {
		invsuf[i] = power(suf[i], P - 2);
	}
	for(int i = n - 1; ~i; --i) {
		sumsuf[i] = (sumsuf[i + 1] + invsuf[i]) % P;
	}
	auto query = [&] (int l, int r) {
		return 1LL * (sumsuf[l] - sumsuf[r] + P) % P * suf[r] % P; 
	};
	set<int> s = {0, n};
	int ans = sumsuf[0];
	while(q--) {
		int u; 
		cin >> u;
		--u;
		if(s.count(u)) {
			auto it = s.find(u);
			int l = *prev(it), r = *next(it);
			ans = (1LL * ans - query(l, u) - query(u, r) + query(l, r)) % P;
			ans = (ans + P) % P;
			s.erase(u);
		} else {
			auto it = s.insert(u).first;
			int l = *prev(it), r = *next(it);
			ans = (1LL * ans + query(l, u) + query(u, r) - query(l, r)) % P;
			ans = (ans + P) % P;
			s.insert(u);
		}
		cout << ans << "\n";
	}
	return 0;
}
