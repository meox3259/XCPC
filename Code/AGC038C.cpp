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

	int n;
	cin >> n;

	int m = 1000001;

	vector<int> mu(m);
	vector<bool> mark(m);
	vector<int> p;
	mu[1] = 1;
	for(int i = 2; i < m; ++i) {
		if(!mark[i]) {
			p.emplace_back(i);
			mu[i] = -1;
		}
		for(int j = 0; j < p.size() && i * p[j] < m; ++j) {
			mark[i * p[j]] = true;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}

	vector<int> cnt(m);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}

	vector<int> s(m);
	for(int i = 1; i < m; ++i) {
		int pre = 0;
		for(int j = i; j < m; j += i) {
			s[i] = (s[i] + 1LL * pre * cnt[j] % P * j % P) % P;
			s[i] = (s[i] + 1LL * cnt[j] * (cnt[j] - 1) / 2 % P * j % P * j % P) % P;
			pre = (pre + 1LL * cnt[j] * j % P) % P;
		}
	}

	int ans = 0;

	for(int d = 1; d < m; ++d) {
		int inv = power(d, P - 2);
		for(int i = 1; d * i < m; ++i) {
			ans = (ans + 1LL * mu[i] * s[d * i] % P * inv % P + P) % P;	
		}
	}

	cout << ans << '\n';

	return 0;
}
