#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll ans = 1;
	ll cnt = 0;
	for(int i = 1; i <= n; ++i) {
		ans = ans * i % P;
	}
	for(int i = 0; i < 2 * n; ++i) {
		if((cnt & 1) == (s[i] == 'B')) {
			ans = ans * cnt % P;
			--cnt;
		} else {
			++cnt;
		}
	}
	if(cnt) {
		cout << 0 << '\n';
	} else {
		cout << ans << '\n';
	}	
	return 0;
}
