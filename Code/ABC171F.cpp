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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	string s;
	cin >> s;

	int n = s.size();

	long long ans = 1;
	int m = 3000001;
	
	vector<long long> fac(m);
	fac[0] = 1;
	for(int i = 0; i + 1 < m; ++i) {
		fac[i + 1] = fac[i] * (i + 1) % P;
	}

	vector<long long> inv(m);
	inv[m - 1] = power(fac[m - 1], P - 2);
	for(int i = m - 1; i >= 1; --i) {
		inv[i - 1] = inv[i] * i % P;
	}

	auto C = [&] (int n, int m) {
		if(n < m) {
			return 0LL;
		}
		return fac[n] * inv[m] % P * inv[n - m] % P;
	};

	for(int i = 0; i <= k; ++i) {
		ans = (ans + C(n - 1 + i, n - 1) * power(25, i) % P * power(26, k - i)) % P;
	}

	cout << (ans - 1 + P) % P << '\n';

	return 0;
}
