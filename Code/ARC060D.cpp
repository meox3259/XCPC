#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
char s[maxn];
void kmp(char *s, vector<int> &nxt) {
	for(int i = 2, j = 0; i <= n; ++i) {
		while(j && s[j + 1] != s[i]) {
			j = nxt[j];
		}
		if(s[j + 1] == s[i]) {
			++j;
		}
		nxt[i] = j;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> s + 1;
	n = strlen(s + 1);
	vector<int> f;
	vector<int> g;
	f.resize(n + 1);
	g.resize(n + 1);
	kmp(s, f);
	for(int i = 1; i <= n; ++i) {
		f[i] = i - f[i];
	}
	reverse(s + 1, s + n + 1);
	kmp(s, g);
	for(int i = 1; i <= n; ++i) {
		g[i] = i - g[i];
	}
	if(f[n] == n || n % f[n] != 0) {
		cout << 1 << '\n' << 1 << '\n';
		return 0;
	}
	if(f[n] == 1) {
		cout << n << '\n' << 1 << '\n';
		return 0;
	}
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		if((f[i] == i || i % f[i] != 0) && (g[n - i] == n - i || (n - i) % g[n - i] != 0)) {
			++ans;
		}
	}
	cout << 2 << '\n' << ans << '\n';
	return 0;
}
