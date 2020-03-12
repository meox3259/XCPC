#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
struct node {
	int a, b, c;
	node() = default;
	node(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
int dp[maxn][maxn][maxn], pre[maxn][maxn][maxn];
char s[maxn], t[maxn];
int H(int a, int b, int c) {
	return a * 1000 * 1000 + b * 1000 + c;
}
node D(int h) {
	return node(h / 1000000, (h / 1000) % 1000, h % 1000);
}
int main() {
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	s[n + 1] = '?';
	t[m + 1] = '?';
	queue<node> q;
	q.push(node(0, 0, 0));
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	while(!q.empty()) {
		auto u = q.front();
		q.pop();
		int a = u.a + (s[u.a + 1] == ')');
		int b = u.b + (t[u.b + 1] == ')');
		int c = u.c - 1;
		if(c >= 0 && dp[a][b][c] == -1) {
			dp[a][b][c] = dp[u.a][u.b][u.c] + 1;
			pre[a][b][c] = H(u.a, u.b, u.c);
			q.push(node(a, b, c));
		}
		a = u.a + (s[u.a + 1] == '(');
		b = u.b + (t[u.b + 1] == '(');
		c = u.c + 1;
		if(c <= 200 && dp[a][b][c] == -1) {
			dp[a][b][c] = dp[u.a][u.b][u.c] + 1;
			pre[a][b][c] = H(u.a, u.b, u.c);
			q.push(node(a, b, c));
		}
	}
	vector<char> ans;
	int a = n, b = m, c = 0;
	for(int i = 0; i < dp[n][m][0]; ++i) {
		node t = D(pre[a][b][c]);
		if(c == t.c + 1) {
			ans.push_back('(');
		} else {
			ans.push_back(')');
		}
		a = t.a;
		b = t.b;
		c = t.c;
	}
	for(int i = ans.size() - 1; ~i; --i) {
		printf("%c", ans[i]);
	}
	return 0;
}
