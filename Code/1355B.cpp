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
		vector<int> e(n);
		for(int i = 0; i < n; ++i) {
			cin >> e[i];
		}
		sort(e.begin(), e.end());
		int cur = 0;
		int ans = 0;
		for(int i : e) {
			++cur;
			if(cur >= i) {
				++ans;
				cur = 0;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
