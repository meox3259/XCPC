#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	long long ans = 0;
	auto check = [&] (int l, int r) {
		for(int i = l; i <= r; ++i) {
			for(int k = 1; i + 2 * k <= r; ++k) {
				if(s[i] == s[i + k] && s[i] == s[i + 2 * k]) {
					return true;
				}
			}
		}
		return false;
	};
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(check(i, j)) {
				ans += n - j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
