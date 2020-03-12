#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<int> > f;
	f.resize(n);
	for(int i = 0; i < n; ++i) {
		f[i].resize(n);
	}
	vector<vector<int> > mx;
	mx.resize(n);
	for(int i = 0; i < n; ++i) {
		mx[i].resize(n);
	}
	for(int i = 0; i < n; ++i) {
		mx[i][i] = a[i];
	}
	for(int i = 0; i < n; ++i) {
		f[i][i] = 1;
	}
	for(int len = 2; len <= n; ++len) {
		for(int i = 0; i + len - 1 < n; ++i) {
			int j = i + len - 1;
			for(int k = i; k < j; ++k) {
				if(mx[i][k] && mx[k + 1][j] && mx[i][k] == mx[k + 1][j]) {
					f[i][j] |= (f[i][k] & f[k + 1][j]);
					if(f[i][j]) {
						mx[i][j] = mx[i][k] + 1;
					}
				}
			}
		}
	} 
	vector<int> dp;
	dp.resize(n + 1, n);
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(f[j][i - 1]) {
				dp[i] = min(dp[i], dp[j] + 1); 
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
