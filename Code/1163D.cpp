#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	string a, b, c;
	cin >> a >> b >> c;
	vector<vector<int> > nb(b.size() + 5, vector<int>(26)), nc(c.size() + 5, vector<int>(26));
	function<void(string, vector<vector<int> >  &)> build = [&] (string s, vector<vector<int> > &nxt) {
		for(int i = 0; i <= s.size(); ++i) {
			for(int c = 0; c < 26; ++c) {
				string tmp = s.substr(0, i) + (char)(c + 'a');
				for(int j = min(i + 1, (int)s.size()); ~j; --j) {
					if(s.substr(0, j) == tmp.substr(tmp.size() - j, j)) {
						nxt[i][c] = j;
						break;
					}
				}
			}
		}
	};
	build(b, nb);
	build(c, nc);
	vector<vector<vector<int> > > dp(a.size() + 1, vector<vector<int> >(b.size() + 1, vector<int>(c.size() + 1, -1e9)));
	dp[0][0][0] = 0;
	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j <= b.size(); ++j) {
			for(int k = 0; k <= c.size(); ++k) {
				for(int x = 0; x < 26; ++x) {
					if(x != a[i] - 'a' && a[i] != '*') {
						continue;
					}
					int tb = nb[j][x];
					int tc = nc[k][x];
					int &t = dp[i + 1][tb][tc];
					t = max(t, dp[i][j][k] + (tb == b.size()) - (tc == c.size()));
				}
			}
		}
	}
	int ans = -1e9;
	for(int j = 0; j <= b.size(); ++j) {
		for(int k = 0; k <= c.size(); ++k) {
			ans = max(ans, dp[a.size()][j][k]);
		}
	}
	cout << ans;
	return 0;
}
