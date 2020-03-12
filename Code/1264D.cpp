#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> inv(n + 1), facinv(n + 1), fac(n + 1);
	fac[0] = inv[1] = facinv[0] = 1;
	for(int i = 1; i <= n; ++i) {
		if(i != 1) {
			inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
		}
		facinv[i] = 1LL * facinv[i - 1] * inv[i] % P;
		fac[i] = 1LL * fac[i - 1] * i % P;
	}
	int a = 0, b = 0, c = 0, d = 0;
	for(auto e : s) {
		if(e == ')') {
			++b;
		}
		if(e == '?') {
			++d;
		}
	}
	map<int, vector<int> > dp;
	auto C = [&] (int n, int m) {
		if(n < m) return 0;
		if(dp.find(n) != dp.end()) {
			return dp[n][m];
		}
		auto &tmp = dp[n];
		int sum = 0;
		tmp.resize(n + 1);
		for(int i = 0; i <= n; ++i) {
			sum += 1LL * fac[n] * facinv[i] % P * facinv[n - i] % P;
			sum %= P;
			tmp[i] = sum;
		}
		return tmp[m];
	};
	auto calc = [&] (int a, int b, int c, int d) {
		int x = min(b + d - a, c + d);
		if(x < 0) return 0;
		return C(c + d, x);
	};
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			++a;
		}
		if(s[i] == ')') {
			--b;
		}
		if(s[i] == '?') {
			++c;
			--d;
		}
		if(s[i] == '(') {
			ans += calc(a, b, c, d);
			ans %= P;
		}
		if(s[i] == '?') {
			++a;
			--c;
			ans += calc(a, b, c, d);
			ans %= P;
			--a;
			++c;
		}
	}
	cout << ans << '\n';
	return 0;
}
