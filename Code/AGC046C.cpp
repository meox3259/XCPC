#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

template <typename T>
void add(T &x, T y) {
	x = (x + y) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int K;
	cin >> K;

	while(!s.empty() && s.back() == '0') {
		s.pop_back();
	}

	while(!s.empty() && *s.begin() == '1') {
		s.erase(s.begin());
	}

	s += '0';

	int n = s.size();
	int cnt = 0;

	vector<int> black;

	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			cnt += 1;
		}
		if(s[i] == '0') {
			black.emplace_back(cnt);
			cnt = 0;
		}
	}

	int m = black.size();
	
	reverse(black.begin(), black.end());

	vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> > (n + 1, vector<long long> (n + 1, 0)));
	dp[0][0][0] = 1;

	int sum = 0;

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j <= sum; ++j) {
			for(int k = 0; k <= sum; ++k) {
				for(int d = -j; d <= black[i]; ++d) {
					add(dp[i + 1][j + d][k + (d < 0 ? 0 : d)], dp[i][j][k]);
				}
			}
		}
		sum += black[i];
	}

	long long ans = 0;
	for(int i = 0; i <= min(K, sum); ++i) {
		add(ans, dp[m][0][i]);
	}

	cout << ans << '\n';

	return 0;
}
