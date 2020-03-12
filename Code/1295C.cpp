#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
char s[maxn], t[maxn];
set<int> a[30];
int nxt[maxn][26];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		for(int i = 0; i < 26; ++i) {
			a[i].clear();
		}
		for(int i = 0; i <= n; ++i) {
			if(i) {
				a[s[i] - 'a'].insert(i);
			}
			for(int j = 0; j < 26; ++j) {
				nxt[i][j] = -1;
			}
		}
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j < 26; ++j) {
				auto it = a[j].upper_bound(i);
				if(it != a[j].end()) {
					nxt[i][j] = *it;
				}
			}
		}
		int p = 0, ans = 0;
		bool f = 1;
		for(int i = 0; i < m; ) {
			if(a[t[i + 1] - 'a'].empty()) {
				f = 0;
				break;
			}
			p = 0;
			while(i + 1 <= m) {
				if(i + 1 <= m && nxt[p][t[i + 1] - 'a'] != -1) {
					p = nxt[p][t[i + 1] - 'a'];
					++i;
				} else {
					break;
				}
			}
			++ans;
		}
		if(!f) {
			puts("-1");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}
