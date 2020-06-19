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

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		vector<int> parse;
		for(int i : a) {
			parse.emplace_back(i);
		}

		sort(parse.begin(), parse.end());
		parse.erase(unique(parse.begin(), parse.end()), parse.end());

		auto id = [&] (int v) {
			return lower_bound(parse.begin(), parse.end(), v) - parse.begin();
		};

		int m = parse.size();
		vector<vector<int> > pos(m);

		for(int i = 0; i < n; ++i) {
			pos[id(a[i])].emplace_back(i);
		}

		int ans = 0;
		for(int i = 0; i < m; ++i) {
			ans = max(ans, (int)pos[i].size());
		}

		vector<int> f(m);

		for(int i = 0; i < m; ++i) {
			f[i] = pos[i].size();
		}

		for(int i = 0; i + 1 < m; ++i) {
			if(*pos[i + 1].begin() > *pos[i].rbegin()) {
				f[i + 1] = max(f[i + 1], f[i] + (int)pos[i + 1].size());
			}
			int p = upper_bound(pos[i].begin(), pos[i].end(), *pos[i + 1].begin()) - pos[i].begin();
			f[i + 1] = max(f[i + 1], (int)pos[i + 1].size() + p);
		}

		ans = max(ans, f[m - 1]);

		for(int i = 0; i + 1 < m; ++i) {
			for(int j = 0; j < pos[i].size(); ++j) {
				int cur = pos[i][j];
				int d = pos[i + 1].end() - lower_bound(pos[i + 1].begin(), pos[i + 1].end(), cur);
				ans = max(ans, j + 1 + d);
			}
		}

		for(int i = 0; i + 1 < m; ++i) {
			int p = pos[i + 1].end() - lower_bound(pos[i + 1].begin(), pos[i + 1].end(), *pos[i].rbegin());
			ans = max(ans, f[i] + p);
		}

		cout << n - ans << '\n';
	}

	return 0;
}
