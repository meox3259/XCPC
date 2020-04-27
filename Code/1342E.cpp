#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

long long power(long long x, long long t) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

int main() {
	int n;
	long long k;

	cin >> n >> k;

	if(k >= n) {
		cout << 0 << '\n';
		return 0;
	}

	vector<long long> fac;
	fac.resize(n + 1);

	fac[0] = 1;
	for(int i = 0; i < n; ++i) {
		fac[i + 1] = fac[i] * (i + 1) % P;
	}

	if(k == 0) {
		cout << fac[n] << '\n';
		return 0;
	}

	vector<long long> inv;
	inv.resize(n + 1);

	inv[n] = power(fac[n], P - 2);
	for(int i = n - 1; i >= 0; --i) {
		inv[i] = inv[i + 1] * (i + 1) % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}

		return fac[n] * inv[m] % P * inv[n - m] % P;
	};

	long long ans = 0;
	long long f = 1;

	for(int i = 0; i <= n - k; ++i) {
		ans = (ans + f * C(n - k, i) * power(n - k - i, n) % P + P) % P; 
		f = -f;
	}

	ans = ans * C(n, n - k) % P * 2 % P;

	cout << ans << '\n';

	return 0;
}
