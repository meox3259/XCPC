#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, ans, pan;
int vis[maxn], cnt[maxn];
int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int p;
		char s[10];
		scanf("%d%s", &p, s);
		if(s[0] == 'A') {
			if(!vis[p]) {
				vis[p] = 1;
				++ans;
				pan += cnt[p];
			}
		}
		if(s[0] == 'W') {
			++cnt[p];
		}
	}
	printf("%d %d\n", ans, pan);
	return 0;
}
