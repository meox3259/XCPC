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
	int n, m;
	cin >> n >> m;

	int k = 3000001;

	vector<long long> fac(k);
	vector<long long> inv(k);

	fac[0] = 1;
	for(int i = 0; i + 1 < k; ++i) {
		fac[i + 1] = fac[i] * (i + 1) % P;
	}

	inv[k - 1] = power(fac[k - 1], P - 2);
	for(int i = k - 1; i >= 1; --i) {
		inv[i - 1] = inv[i] * i % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}
		return fac[n] * inv[m] % P * inv[n - m] % P;
	};

	long long ans = 0;
	for(int i = 0; i + i <= m; ++i) {
		if(m - 2 * i <= n) {
			int two = m + i;
			ans = (ans + C(two + n - 1, n - 1) * C(n, m - 2 * i) % P) % P;
		}
	}

	ans = (ans - C(m - 1 + n - 1, n - 1) * n % P + P) % P;

	cout << ans << '\n';

	return 0;
}
