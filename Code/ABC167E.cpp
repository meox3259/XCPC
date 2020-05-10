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
	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> fac(n + 1);
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}

	vector<long long> inv(n + 1);
	inv[n] = power(fac[n], P - 2);

	for(int i = n; i >= 1; --i) {
		inv[i - 1] = inv[i] * i % P;
	}

	auto C = [&] (int n, int m) {
		if(m > n) {
			return 0LL;
		}
		return fac[n] * inv[m] % P * inv[n - m] % P;
	};

	long long ans = 0;

	for(int i = n - k - 1; i < n; ++i) {
		ans = (ans + C(n - 1, i) * power(m - 1, i) % P * m % P) % P;
	}

	cout << ans << '\n';

	return 0;
}
