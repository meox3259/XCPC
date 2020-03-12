#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> ans;
		for(int i = 0; i < n; ++i) {
			if(i + 2 < n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
				if(i > 0 && s[i - 1] != 'o') {
					ans.push_back(i);
				} else {
					ans.push_back(i + 1);
				}
			}
			if(i - 2 >= 0 && s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o') {
				if(i + 1 < n && s[i + 1] != 'o') {
					ans.push_back(i);
				} else {
					ans.push_back(i - 1);
				}
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << ans.size() << '\n';
		for(auto x : ans) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
