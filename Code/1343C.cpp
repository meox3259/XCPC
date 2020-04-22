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

		vector<int> st;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			if(st.empty()) {
				st.emplace_back(x);
			} else {
				if((st.back() > 0) != (x > 0)) {
					st.emplace_back(x);
				} else {
					int &v = st[(int)st.size() - 1];
					v = max(v, x);
				}
			}
		}

		long long ans = 0;

		for(int i : st) {
			ans += i;
		}

		cout << ans << '\n';
	}

	return 0;
}
