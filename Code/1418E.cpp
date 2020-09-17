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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> d(n);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	sort(d.begin(), d.end());

	vector<long long> pre(n + 1);
	for(int i = 0; i < n; ++i) {
		pre[i + 1] = (pre[i] + d[i]) % P;
	}

	vector<int> a(m);
	vector<int> b(m);
	for(int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<long long> fac(n + 1);
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}

	vector<long long> facinv(n + 1);
	facinv[n] = power(fac[n], P - 2);
	for(int i = n; i >= 1; --i) {
		facinv[i - 1] = facinv[i] * i % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}
		return fac[n] * facinv[m] % P * facinv[n - m] % P;
	};

	for(int i = 0; i < m; ++i) {
		int small = lower_bound(d.begin(), d.end(), b[i]) - d.begin();
		int big = n - small;
		long long sumsmall = pre[small];
		long long sumbig = (pre[n] - sumsmall + P) % P;
		if(big < a[i]) {
			cout << 0 << '\n';
		} else {
			long long ans = 0;	
			ans += 1LL * (big + 1 - a[i]) * power(big + 1, P - 2) % P * sumsmall % P;
			ans += 1LL * (big - a[i]) * power(big, P - 2) % P * sumbig % P;
			ans %= P;
			cout << ans << '\n';
		}
	}

	return 0;
}
