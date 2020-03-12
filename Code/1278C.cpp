#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
map<int, int> mp;
int n;
int a[maxn], b[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int c1 = 0, c2 = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			c1 += (a[i] == 1);
			c2 += (a[i] == 2);
		}
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			c1 += (b[i] == 1);
			c2 += (b[i] == 2);
		}
		mp.clear();
		int t1 = 0, t2 = 0, d = c2 - c1;
		mp[0] = 0;
		for(int i = n; i; --i) {
			t1 += (a[i] == 1);
			t2 += (a[i] == 2);
			if(!mp.count(t2 - t1)) mp[t2 - t1] = n - i + 1; 
		}
		t1 = t2 = 0;
		int ans = 2 * n;
		if(mp.count(d)) ans = min(ans, mp[d]);
		for(int i = 1; i <= n; ++i) {
			t1 += (b[i] == 1);
			t2 += (b[i] == 2);
			if(mp.count(d - (t2 - t1))) ans = min(ans, mp[d - (t2 - t1)] + i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
