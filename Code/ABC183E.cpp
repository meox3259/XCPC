#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	for(int i = 0; i < h; ++i) {
		cin >> s[i];
	}

	vector<vector<long long> > dp(h, vector<long long> (w));
	vector<long long> x(h);
	vector<long long> y(w);
	vector<long long> z(h + w);

	dp[0][0] = 1;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(s[i][j] == '.') {
				dp[i][j] = (dp[i][j] + x[i] + y[j] + z[i - j + w]) % P;	
				x[i] = (x[i] + dp[i][j]) % P;
				y[j] = (y[j] + dp[i][j]) % P;
				z[i - j + w] = (z[i - j + w] + dp[i][j]) % P;
			} else {
				x[i] = 0;
				y[j] = 0;
				z[i - j + w] = 0;
			}	
		}
	}

	cout << dp[h - 1][w - 1] << '\n';

	return 0;
}
