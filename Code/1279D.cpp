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

	vector<vector<int> > G(n);
	vector<int> people(1000001);

	for(int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for(int j = 0; j < k; ++j) {
			int present;
			cin >> present;
			--present;
			G[i].emplace_back(present);
			++people[present];
		}
	}

	long long ans = 0;
	long long inv = power(n, P - 2);

	for(int i = 0; i < n; ++i) {
		long long p = inv * power(G[i].size(), P - 2) % P;
		for(int j : G[i]) {
			ans = (ans + p * people[j] % P * inv % P) % P;
		}
	}

	cout << ans << '\n';

	return 0;
}
