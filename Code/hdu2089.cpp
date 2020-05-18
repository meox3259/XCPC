#include <bits/stdc++.h>

using namespace std;

int st[105];
int top = 0;

int dp[10][2];

int dfs(int bit, int state, int lim) { 
	if(bit == 0) {
		return 1;
	}

	if(!lim && dp[bit][state] != -1) {
		return dp[bit][state];
	}

	int sum = 0;
	int Bound = lim ? st[bit] : 9; 

	for(int i = 0; i <= Bound; ++i) {
		int Next_state = -1;
		if(i == 4) {
			continue;
		}
		if(state == 1 && i == 2) {
			continue;
		}
		if(i == 6) {
			Next_state = 1;
		} else {
			Next_state = 0;
		}
		sum += dfs(bit - 1, Next_state, lim && (i == Bound));
	}

	if(!lim) {
		dp[bit][state] = sum;
	}

	return sum;
}

int solve(int x) {
	top = 0;
	while(x) {
		st[++top] = x % 10;
		x /= 10;
	}

	return dfs(top, 0, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n, m;

	while(cin >> n >> m) {
		if(n == 0 && m == 0) {
			break;
		}
		cout << solve(m) - solve(n - 1) << '\n';
	}

	return 0;
}
