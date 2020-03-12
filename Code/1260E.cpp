#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 19) + 5;
int n;
int a[maxn];
int main() {
	scanf("%d", &n);
	multiset<int> s;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for(int i = n; i && ~a[i]; --i) {
		s.insert(a[i]);
		if(!(i & (i - 1))) {
			ans += *s.begin();
			s.erase(s.begin());
		}
	}
	printf("%lld\n", ans);
	return 0;
}
