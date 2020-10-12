#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> w(n);
	for(int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	vector<int> l(m);
	vector<int> v(m);
	for(int i = 0; i < m; ++i) {
		cin >> l[i] >> v[i];
	}

	vector<pair<int, int> > b;
	for(int i = 0; i < m; ++i) {
		b.emplace_back(v[i], l[i]);
	}

	sort(b.begin(), b.end());
	for(int i = 0; i + 1 < b.size(); ++i) {
		b[i + 1].second = max(b[i + 1].second, b[i].second);
	}

	vector<int> id(n);
	iota(id.begin(), id.end(), 0);

	if(*max_element(w.begin(), w.end()) > *min_element(v.begin(), v.end())) {
		cout << -1 << '\n';
		exit(0);
	}

	int ans = 1000000000;
	do {
		vector<vector<int> > d(n, vector<int> (n));
		for(int i = 0; i < n; ++i) {
			int sum = 0;
			for(int j = i; j < n; ++j) {
				sum += w[id[j]];
				auto it = upper_bound(b.begin(), b.end(), make_pair(sum, 0));
				if(it != b.begin()) {
					it = prev(it);
					d[i][j] = max(d[i][j], it -> second);
				}
			}
		}

		for(int l = 0; l < n; ++l) {
			for(int i = 0; i + l < n; ++l) {
				for(int j = i; j <= i + l; ++j) {
					d[i][i + l] = max(d[i][i + l], d[i][j] + d[j][i + l]);
				}
			}
		}

		ans = min(ans, d[0][n - 1]);
	} while(next_permutation(id.begin(), id.end()));

	cout << ans << '\n';

	return 0;
}
