#include <bits/stdc++.h>

using namespace std;

const long long P = 998244353;

using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<ll> fac;
	vector<ll> inv;
	vector<ll> facinv;
	fac.resize(m + 1);
	inv.resize(m + 1);
	facinv.resize(m + 1);
	fac[0] = 1;
	inv[1] = 1;
	facinv[0] = 1;
	for(int i = 1; i < m + 1; ++i) {
		fac[i] = fac[i - 1] * i % P;
		if(i != 1) {
			inv[i] = inv[P % i] * (P - P / i) % P;
		}
		facinv[i] = facinv[i - 1] * inv[i] % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}
		return fac[n] * facinv[m] % P * facinv[n - m] % P;
	};

	ll ans = 0;

	for(int i = 2; i < n; ++i) {
		ans = (ans + C(m, n - 1) * C(n - 2, i - 1) % P * (i - 1) % P) % P;
	}
	cout << ans << '\n';
	return 0;
}
