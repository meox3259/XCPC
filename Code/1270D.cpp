#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, k, top;
int st[maxn];
pair<int, int> ask() {
	printf("?");
	for(int i = 1; i <= top; ++i) {
		printf(" %d", st[i]);
	}
	puts("");
	fflush(stdout);
	int p, v;
	scanf("%d%d", &p, &v);
	return make_pair(p, v);
}
int main() {
	scanf("%d%d", &n, &k);
	int mx = -1, ans = 0;
	for(int i = 1; i <= k + 1; ++i) {
		top = 0;
		for(int j = 1; j <= k + 1; ++ j) {
			if(i != j) {
				st[++top] = j;
			}
		}
		pair<int, int> o = ask();
		int tmp = max(mx, o.second);
		if(o.second == mx) {
			++ans;
		} else if(o.second > mx) {
			ans = 1;
		}
		mx = max(mx, o.second);
	}
	printf("! %d\n", ans);
	fflush(stdout)
	return 0;
}
