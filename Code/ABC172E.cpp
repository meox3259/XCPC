#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

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
	int n, m;
	cin >> n >> m;

	vector<long long> fac(m + 1);
	fac[0] = 1;
	for(int i = 0; i < m; ++i) {
		fac[i + 1] = fac[i] * (i + 1) % P;
	}

	vector<long long> inv(m + 1);
	inv[m] = power(fac[m], P - 2);
	for(int i = m; i >= 1; --i) {
		inv[i - 1] = inv[i] * i % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}
		return fac[n] * inv[m] % P * inv[n - m] % P;
	};

	long long ans = 0;
	for(int i = 0; i <= n; ++i) {
		long long x = C(n, i) * C(m - i, n - i) % P * fac[n - i] % P;
		if(i % 2 == 0) {
			ans = (ans + x) % P;
		} else {
			ans = (ans - x + P) % P;
		}
	}

	ans = ans * fac[n] % P * C(m, n) % P;

	cout << ans << '\n';

	return 0;
}
