#include <bits/stdc++.h>

using namespace std;

const int N = 10000005;
const int P = 1000000007;

long long power(long long x, long long t) {
	long long ret = 1;
	for (; t; t >>= 1, x = x * x % P) {
		if (t & 1) {
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

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> inv(N);
	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
	}

	auto C = [&] (int n, int m) {
		if (n < m) {
			return 0LL;
		}
		long long ret = 1;
		for (int i = 1; i <= m; ++i) {
			ret = ret * (n - i + 1) % P;
			ret = ret * inv[i] % P;
		}	
		return ret;
	};

	int s = 0;
	for (int i : a) {
		s += i;
	}

	cout << C(m + n, s + n) << '\n';

	return 0;
}
