#include <bits/stdc++.h>

using namespace std;

long long power(long long x, long long t, long long P) {
	long long ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}

int main() {
	int n, x, p, m;
	cin >> n >> x >> p >> m;

	vector<long long> a(m + 1);
	for(int i = 0; i <= m; ++i) {
		cin >> a[i];
	}

	vector<long long> down(m + 1);
	down[0] = 1;
	for(int i = 0; i < m; ++i) {
		down[i + 1] = down[i] * (n - i) % p;
	}

	vector<vector<long long> > S(m + 2, vector<long long> (m + 2));
	S[1][1] = 1;
	for(int i = 2; i <= m; ++i) {
		for(int j = 1; j <= i; ++j) {
			S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]) % p;
		}
	}

	long long ans = 0;
	ans = a[0] * power(x + 1, n, p) % p;
	for(int i = 1; i <= m; ++i) {
		long long t = 0;
		for(int j = 0; j <= i; ++j) {
			t = (t + S[i][j] * down[j] % p * power(x, j, p) % p * power(x + 1, n - j, p)) % p;
		}
		t = t * a[i] % p;
		ans = (ans + t) % p;
	}

	cout << ans << '\n';

	return 0;
}
