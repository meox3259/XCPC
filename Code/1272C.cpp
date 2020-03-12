#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<char> c(k);
	for(int i = 0; i < k; ++i) {
		cin >> c[i];
	}
	int pre = -1;
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		bool f = 0;
		for(int j = 0; j < k; ++j) {
			if(s[i] == c[j]) {
				f = 1;
				break;
			}
		}
		if(f) {
			ans += i - pre;
		} else {
			pre = i;
		}
	}
	cout << ans << '\n';
	return 0;
}
