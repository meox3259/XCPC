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

	int n;
	cin >> n;

	vector<long long> a(n);
	vector<long long> b(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	map<pair<long long, long long>, int> mp;

	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		long long A, B;
		A = a[i];
		B = b[i];
		long long d = __gcd(A, B);
		if(d == 0) {
			++cnt;
			continue;
		}
		A /= d;
		B /= d;
		if(A < 0) {
			A = -A;
			B = -B;
		}
		++mp[{ A, B }];
	}	

	map<pair<long long, long long>, bool> vis;

	long long ans = 1;

	for(auto it : mp) {
		auto o = it.first;
		long long A = o.first;
		long long B = o.second;
		if(vis.count({ A, B })) {
			continue;
		}
		long long d = power(2, mp[{ A, B }]);
		B = -B;
		if(B < 0) {
			B = -B;
			A = -A;
		}
		pair<long long, long long> v = { B, A }; 
		if(mp.count(v)) {
			d = (d + power(2, mp[v]) - 1) % P;
			vis[v] = true;
		}

		ans = ans * d % P;
	}

	cout << (ans - 1 + cnt + P) % P << '\n';

	return 0;
}
