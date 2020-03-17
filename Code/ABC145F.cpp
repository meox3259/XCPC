#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, K;
	cin >> n >> K;

	vector<int> h;
	h.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	vector<vector<vector<ll> > > dp;

	dp.resize(n + 1);

	for(int i = 0; i < n + 1; ++i) {
		dp[i].resize(n + 1);

		for(int j = 0; j < n + 1; ++j) {
			dp[i][j].assign(n + 1, inf);
		}
	}

	dp[0][0][0] = 0;

	vector<int> v = h;

	v.emplace_back(0);

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	vector<int> id;
	id.resize(n);

	for(int i = 0; i < n; ++i) {
		id[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
	}

	for(int i = 0; i < n; ++i) {
		vector<vector<ll> > pre;
		pre.resize(n + 1);

		for(int i = 0; i < n + 1; ++i) {
			pre[i].resize(n + 1);
		}
		
		vector<vector<ll> > suf;
		suf.resize(n + 1);

		for(int i = 0; i < n + 1; ++i) {
			suf[i].resize(n + 1);
		}
		
		for(int j = 0; j <= K; ++j) {
			pre[j][0] = dp[i][j][0] - v[0];

			for(int k = 0; k + 1 < v.size(); ++k) {
				pre[j][k + 1] = min(pre[j][k], dp[i][j][k + 1] - v[k + 1]);
			}
		}

		for(int j = 0; j <= K; ++j) {
			suf[j][(int)v.size() - 1] = dp[i][j][(int)v.size() - 1];
			
			for(int k = (int)v.size() - 2; k >= 0; --k) {
				suf[j][k] = min(suf[j][k + 1], dp[i][j][k]);
			}
		}
		
		for(int j = 0; j <= K; ++j) {
			for(int k = 0; k < v.size(); ++k) {
				dp[i + 1][j][id[i]] = min(dp[i + 1][j][id[i]], dp[i][j][k] + max(0, v[id[i]] - v[k]));
			} 
	
			if(j < K) {
				for(int k = 0; k < v.size(); ++k) {
					dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], v[k] + pre[j][k]);
					dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], suf[j][k]);
				}
			}
		}
	}

	cout << *min_element(dp[n][K].begin(), dp[n][K].end()) << '\n';

	return 0;

}
