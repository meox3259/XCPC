#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		string s;
		cin >> n >> s;
		string ans = s;
		int p = 1;
		for(int i = 2; i <= n; ++i) {
			string x = s.substr(0, i - 1);
			string y = s.substr(i - 1, n - i + 1);
			if((n - i + 1) & 1) {
				reverse(x.begin(), x.end());
			}
			if(y + x < ans) {
				ans = y + x;
				p = i;
			}
		}
		cout << ans << '\n';
		cout << p << '\n';
	}
	return 0;
}
