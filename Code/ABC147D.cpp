#include <bits/stdc++.h>
const int P = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<long long> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> sum;
	sum.resize(60);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 60; ++j) {
			if(a[i] >> j & 1) {
				ans = (ans + (1LL << j) % P * (i - sum[j])) % P;
			} else {
				ans = (ans + (1LL << j) % P * sum[j]) % P;
			}
			sum[j] += a[i] >> j & 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
