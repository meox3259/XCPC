#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int k, l;
		cin >> k >> l;

		if(l >= 2000) {
			cout << "-1" << '\n';
			continue;
		}

		vector<int> ans;
		ans.emplace_back(-1);
		int tot = k + 1999;
		for(int i = 0; i < 1998; ++i) {
			if(tot >= 1000000) {
				tot -= 1000000;
				ans.emplace_back(1000000);
			} else {
				ans.emplace_back(tot);
				tot = 0;
			}
		}

		cout << ans.size() << '\n';
		for(int i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}
