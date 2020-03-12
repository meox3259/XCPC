#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		int n = s.size();
		int m = t.size();
		vector<vector<int> > nxt;
		nxt.resize(n);
		for(int i = 0; i < n; ++i) {
			nxt[i].assign(26, -1);
			for(int j = n - 1; j > i; --j) {
				nxt[i][s[j] - 'a'] = j;
			}
		}
		auto solve = [&] (int len) {
			string s1 = t.substr(0, len);
			string s2 = t.substr(len, m - len);
			int x = s1.size();
			int y = s2.size();
			vector<vector<int> > dp;
			dp.resize(x + 2);
			for(int i = 0; i < x + 1; ++i) {
				dp[i].assign(y + 2, -1);
			}
			for(int i = 0; i < n; ++i) {
				if(s[i] == s1[0]) {
					dp[1][0] = i;
					break;
				}
			}
			for(int i = 0; i < n; ++i) {
				if(s[i] == s2[0]) {
					dp[0][1] = i;
					break;
				}
			}
			for(int i = 0; i < x + 1; ++i) {
				for(int j = 0; j < y + 1; ++j) {
					if(dp[i][j] != -1) {
						if(i < x) {
							int tmp = nxt[dp[i][j]][s1[i] - 'a'];
							if(tmp != -1 && (tmp < dp[i + 1][j] || dp[i + 1][j] == -1)) {
								dp[i + 1][j] = tmp;
							}
						}
						if(j < y) {
							int tmp = nxt[dp[i][j]][s2[j] - 'a'];
							if(tmp != -1 && (tmp < dp[i][j + 1] || dp[i][j + 1] == -1)) {
								dp[i][j + 1] = tmp;
							}
						}
					}
				}
			}
			if(dp[x][y] != -1) {
				return true;
			} else {
				return false;
			}
		};
		bool f = 0;
		for(int len = 0; len < m; ++len) {
			if(solve(len)) {
				f = 1;
				break;
			}	
		}		
		if(f == 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
