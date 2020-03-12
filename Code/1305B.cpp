#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	set<int> S;
	for(int i = 0; i < n; ++i) {
		if(s[i] == ')') {
			S.emplace(i);
		}
	}
	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			if(S.empty() || *S.rbegin() < i) {
				break;
			} else {
				ans.emplace_back(i);
				ans.emplace_back(*S.rbegin());
				S.erase(*S.rbegin());
			}
		}
	}
	if(ans.empty()) {
		cout << '0' << '\n';
		return 0;
	}
	cout << 1 << '\n';
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for(auto x : ans) {
		cout << x + 1 << ' ';
	}
	cout << '\n';
	return 0;
}
