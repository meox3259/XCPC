#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> zero;
		vector<int> one;
		vector<int> ans(n);
		int id = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '0') {
				if(!one.empty()) {
					zero.emplace_back(one.back());
					ans[i] = one.back();
					one.pop_back();
				} else {
					ans[i] = ++id;
					zero.emplace_back(id);
				}
			} else {
				if(!zero.empty()) {
					one.emplace_back(zero.back());
					ans[i] = zero.back();
					zero.pop_back();
				} else {
					ans[i] = ++id;
					one.emplace_back(id);
				}
			}
		}

		cout << one.size() + zero.size() << '\n';
		for(int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}
