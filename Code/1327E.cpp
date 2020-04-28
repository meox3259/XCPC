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
	int n;
	cin >> n;

	vector<long long> ans;
	ans.resize(n);

	for(int i = 0; i < n; ++i) {
		ans[i] = power(10, n - i) * (n - i) % P;
	}

	long long suf = 0;
	long long sum = 0;

	for(int i = n - 1; i >= 0; --i) {
		ans[i] = (ans[i] - sum - suf + P * 2) % P;
		suf = (suf + ans[i]) % P;
		sum = (sum + suf) % P;
	}

	for(long long i : ans) {
		cout << i << ' ';
	}

	cout << '\n';

	return 0;
}
