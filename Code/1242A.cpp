#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	long long n, t; cin >> n;
	t = n;
	long long ans = n, cnt = 0;
	for(long long i = 2; i * i <= n; ++i) {
		if(t % i == 0) {
			ans = i;
			++cnt;
			while(t % i == 0) {
				t /= i;
			}
		}
	}
	if(t > 1) {
		++cnt;
		ans = t;
	}
	if(cnt > 1) {
		cout << 1 << "\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
