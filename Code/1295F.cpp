#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 105, P = 998244353;
int n;
int l[maxn], r[maxn];
ll dp[maxn][maxn];
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P) {
		if(t & 1) {
			ret = ret * x % P;
		}
	}
	return ret;
}
int main() {
	cin >> n;
	vector<int> v;
	ll inv = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		++r[i];
		v.emplace_back(l[i]);
		v.emplace_back(r[i]);
		inv = inv * (r[i] - l[i]) % P;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; ++i) {
		l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
	}
	int m = v.size();
	for(int i = 0; i <= m; ++i) {
		dp[0][i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(l[i] > j || r[i] <= j) {
				continue;
			}
			int len = v[j + 1] - v[j];
			ll tmp = 1;
			for(int k = i; k; --k) {
				if(l[k] > j || r[k] <= j) {
					break;
				}
				tmp = tmp * (len + i - k) % P * power(i - k + 1, P - 2) % P;
				dp[i][j] = (dp[i][j] + dp[k - 1][j + 1] * tmp % P) % P;
			}
		}
		for(int j = m; j; --j) {
			dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % P;
		}
	}
	cout << dp[n][0] * power(inv, P - 2) % P << '\n';
	return 0;
}
