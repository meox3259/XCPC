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

		multiset<int> s;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			s.emplace(x);
		}

		vector<int> ans;

		while(!s.empty()) {
			int x = *s.rbegin();
			s.erase(s.find(x));
			ans.emplace_back(x);
	
			if(s.empty()) {
				break;
			}

			int y = *s.begin();
			s.erase(s.find(y));

			ans.emplace_back(y);
		}

		for(int i = n - 1; i >= 0; --i) {
			cout << ans[i] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
