#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		string s;
		cin >> n >> s;
		int p = 0;
		vector<int> ans;
		ans.resize(n);
		for(int i = n - 2; i >= 0; --i) {
			if(s[i] == '<') {
				int j = i;
				while(s[j] == '<') {
					--j;
				}
				for(int k = j + 1; k <= i; ++k) {
					ans[k] = ++p;
				}
				i = j;
			}
		}
		int t = n;
		for(int i = 0; i < n; ++i) {
			if(!ans[i]) {
				ans[i] = t--;
			}
		}
		for(int i = 0; i < n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		ans.assign(n, 0);
		p = 0;
		for(int i = 0; i < n - 1; ++i) {
			if(s[i] == '<') {
				ans[i] = ++p;
			}
		}
		t = n;
		for(int i = 0; i < n; ++i) {
			if(!ans[i]) {
				ans[i] = t--;
			}
		}
		for(int i = 0; i < n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
