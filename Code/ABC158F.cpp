#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int inf = 2e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int> > x;
	x.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(), x.end());
	vector<int> p;
	p.resize(n);
	for(int i = 0; i < n; ++i) {
		p[i] = x[i].first;
	}
	vector<int> dp;
	dp.resize(n + 1);
	dp[n] = 1;
	vector<pair<int, int> > st;
	st.emplace_back(inf, n);
	for(int i = n - 1; i >= 0; --i) {
		while(x[i].first + x[i].second > st.back().first) {
			st.pop_back();
		}
		dp[i] = (dp[i + 1] + dp[st.back().second]) % P;
		st.emplace_back(x[i].first, i);
	}
	cout << dp[0] << '\n';
	return 0;
}

