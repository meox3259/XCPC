#include <iostream>
#include <vector>

using namespace std;

const long long inf = 1000000000000000000;

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

	vector<long long> dp;
	dp.resize(n);

	vector<long long> sum;
	sum.resize(n);

	for(int i = 0; i < n; ++i) {
		sum[i] = (i >= 2 ? sum[i - 2] : 0) + a[i];
	}
	
	dp[1] = max(a[0], a[1]);

	for(int i = 2; i < n; ++i) {
		if(!(i & 1)) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		} else {
			dp[i] = max(sum[i - 1], dp[i - 2] + a[i]);
		}
	}

	cout << dp[n - 1] << '\n';

	return 0;
}
