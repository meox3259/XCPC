#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class BracketSequenceDiv1 {
	public:
		int n;
		string s;
		ll dp[105][105];
		ll dfs(int l, int r) {
			if(l >= r) return 1;
			if(dp[l][r] >= 0) return dp[l][r];
			dp[l][r] = dfs(l + 1, r);
			for(int i = l + 1; i <= r; ++i) {
				if((s[l] == '(' && s[i] == ')') || (s[l] == '[' && s[i] == ']')) dp[l][r] += dfs(l + 1, i - 1) * dfs(i + 1, r);
			}
			return dp[l][r];
		}
		long long count(string t) {
			n = t.size();
			s = t;
			memset(dp, -1, sizeof(dp));
			return dfs(0, n - 1) - 1;
		}
};

/*
 dp[i][j][k][a][b] : 前i有j个(k个[
*/

