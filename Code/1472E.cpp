#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<tuple<int, int, int> > p;
		for (int i = 0; i < n; ++i) {
			int h, w;
			cin >> h >> w;
			if (h > w) {
				swap(h, w);
			}
			p.emplace_back(h, w, i);
		}

		sort(p.begin(), p.end());
		
		set<pair<int, int> > s;
		vector<int> ans(n, -1);

		for (int i = 0, j = 0; i < n; ++i) {
			auto [h, w, o] = p[i];
			while (j < n) {
				auto [hj, wj, oj] = p[j];
				if (hj < h) {
					s.emplace(wj, oj);
					j ++;
				} else {
					break;
				}
			}
			auto it = s.lower_bound(make_pair(w, -1));
			if (it != s.begin()) {
				ans[o] = prev(it) -> second + 1;
			}
		}

		for (int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}
