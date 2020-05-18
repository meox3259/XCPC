#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

map<pair<long long, long long>, int> dp;

int calc(long long u, long long v) {
	if(v < 0) {
		return 0;
	}
	if(v == 0) {
		return 1;
	}
	if(dp.count({ u, v })) {
		return dp[{ u, v }];
	}
	int ret = 0; // u = a ^ b v =  a ^ b + 2(a & b)
	ret = (ret + calc(u >> 1, v >> 1)) % P; // a == 0 && b == 0 a ^ b == 0 && a & b == 0 x + 0 <= u-> x <= u
	ret = (ret + calc((u - 1) >> 1, (v - 1) >> 1)) % P; // a ^ b == 1 x + 1 <= u y + 1 <= u
	ret = (ret + calc((u - 1) >> 1, (v - 2) >> 1)) % P; // a == 1 && b == 1 a ^ b == 0 a & b = 2
	return dp[{ u, v }] = ret;
}

int main() {
	long long n;
	cin >> n;

	cout << calc(n, n) << '\n';

	return 0;
}
