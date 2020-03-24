#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<long long> > dp;
	dp.resize(k + 1);

	vector<int> block;
	vector<int> len;

	for(int i = 1, j; i <= n; i = j + 1) {
		j = n / (n / i);

		block.emplace_back(i);
		len.emplace_back(j - i + 1);
	}

	int m = len.size();

	for(int i = 0; i < k + 1; ++i) {
		dp[i].resize(m);
	}

	dp[0].assign(m, 1);

	auto find = [&] (int x) {
		return upper_bound(block.begin(), block.end(), x) - block.begin() - 1;
	};

	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < m; ++j) {
			dp[i + 1][j] = dp[i][find(n / block[j])] * len[j] % P;
		}

		for(int j = 0; j < m - 1; ++j) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j]) % P;
		}
	}

	cout << dp[k].back() << '\n';

	return 0;
}
