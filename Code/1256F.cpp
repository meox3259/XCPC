#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int cnt[30], b[maxn][2];
char s[maxn], t[maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%s%s", &n, s + 1, t + 1);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) {
			++cnt[s[i] - 'a'];
			--cnt[t[i] - 'a'];
		}
		bool f = 1;
		for(int i = 0; i < 26; ++i) {
			if(cnt[i]) {
				f = 0;
				break;
			}
		}
		if(!f) {
			puts("NO");	
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) {
			++cnt[s[i] - 'a'];
		}
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] > 1) {
				f = 0;
				break;
			}
		}
		if(!f) {
			puts("YES");
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) {
			++cnt[t[i] - 'a'];
		}
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] > 1) {
				f = 0;
				break;
			}
		}
		if(!f) {
			puts("YES");
			continue;
		}
		int c1 = 0, c2 = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j < i; ++j) {
				c1 += s[i] < s[j];
				c2 += t[i] < t[j];
			}
		}
		puts((c1 & 1) != (c2 & 1) ? "NO" : "YES");
	}
	return 0;
}
