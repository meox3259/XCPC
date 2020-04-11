#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int low = 0;
	int high = 0;

	vector<vector<int> > ans;

	while(1) {
		vector<int> tmp;
		for(int i = 0; i < n - 1; ++i) {
			if(s[i] == 'R' && s[i + 1] == 'L') {
				++high;
				tmp.emplace_back(i);
			}
		}

		if(tmp.empty()) {
			break;
		}

		for(int i : tmp) {
			swap(s[i], s[i + 1]);
		}

		ans.emplace_back(tmp);
	}

	low = ans.size();

	if(k < low || k > high) {
		cout << -1 << '\n';
		return 0;
	}

	k -= low;

	for(int i = 0; i < low; ++i) {
		int d = min(k, (int)ans[i].size() - 1);
		k -= d;

		for(int j = 0; j < d; ++j) {
			cout << 1 << ' ' << ans[i].back() + 1 << '\n';
			ans[i].pop_back();
		}

		cout << ans[i].size();
		for(int x : ans[i]) {
			cout << ' ' << x + 1;
		}

		cout << '\n';
	}

	return 0;
}
