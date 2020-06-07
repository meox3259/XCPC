#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const int M = 1141919810;

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long p;
		cin >> n >> p;
		vector<int> k(n);
		for(int i = 0; i < n; ++i) {
			cin >> k[i];
		}

		sort(k.begin(), k.end(), greater<int> ());

		long long ans1 = 0;
		long long ans2 = 0;

		for(int i : k) {
			if(!ans1 && !ans2) {
				ans1 += power(p, i, P);
				ans2 += power(p, i, M);
			} else {
				ans1 = (ans1 - power(p, i, P) + P) % P;
				ans2 = (ans2 - power(p, i, M) + M) % M;
			}
		}

		cout << ans1 << '\n';
	}

	return 0;
}
