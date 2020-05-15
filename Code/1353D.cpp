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
		
		vector<int> ans(n);

		set<tuple<int, int, int> > s;

		s.emplace(-n, 0, n - 1);

		for(int i = 0; i < n; ++i) {
			auto [len, l, r] = *s.begin();
			s.erase(s.begin());
			ans[(l + r) / 2] = i;
			int mid = (l + r) / 2;
			if(mid - 1 >= l) {
				s.emplace(l - mid, l, mid - 1);
			}
			if(mid + 1 <= r) {
				s.emplace(mid - r, mid + 1, r);
			}
		}

		for(int i : ans) {
			cout << i + 1 << ' ';
		}

		cout << '\n';
	}

	return 0;
}
