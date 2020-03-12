#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s;
	s.resize(n);
	vector<string> ans;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	string mid = "";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			string tmp = s[j];
			reverse(tmp.begin(), tmp.end());
			if(tmp == s[i]) {
				ans.emplace_back(s[i]);
				break;
			}
		}
		string tmp = s[i];
		reverse(tmp.begin(), tmp.end());
		if(tmp == s[i]) {
			mid = s[i];
		}
	}
	int len = mid.size();
	for(int i = 0; i < ans.size(); ++i) {
		len += ans[i].size() * 2;
	}
	cout << len << '\n';
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
	}
	cout << mid;
	for(int i = (int)ans.size() - 1; ~i; --i) {
		string tmp = ans[i];
		reverse(tmp.begin(), tmp.end());
		cout << tmp;
	}
	cout << '\n';
	return 0;
}
