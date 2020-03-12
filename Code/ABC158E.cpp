#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, P;
	cin >> n >> P;
	string s;
	cin >> s;
	vector<long long> pow;
	if(P == 2 || P == 5) {
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			if((s[i] - '0') % P == 0) {
				ans += i + 1;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	pow.resize(n + 1);
	pow[0] = 1;
	for(int i = 1; i <= n; ++i) {
		pow[i] = pow[i - 1] * 10 % P;
	}
	auto power = [&] (long long x, long long t) {
		long long ret = 1;
		for(; t; t >>= 1, x = x * x % P) {
			if(t & 1) {
				ret = ret * x % P;
			}
		}
		return ret;
	};
	long long sum = 0;
	vector<long long> cnt;
	cnt.resize(P);
	cnt[0] = 1;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		sum = (sum * 10 + s[i - 1] - '0') % P;
		ans += cnt[sum * power(pow[i], P - 2) % P];
		++cnt[sum * power(pow[i], P - 2) % P];
	}
	cout << ans << '\n';
	return 0;
}
