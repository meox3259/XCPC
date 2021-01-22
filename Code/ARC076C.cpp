#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c;
	cin >> r >> c;

	int n;
	cin >> n;

	vector<pair<int, int> > obj;
	for (int i = 0; i < n; ++i) {
		vector<int> x(2);
		vector<int> y(2);
		for (int j = 0; j < 2; ++j) {
			cin >> x[j] >> y[j];
		}

		int cnt = 0;
		for (int j = 0; j < 2; ++j) {
			cnt += (x[j] == 0 || x[j] == r || y[j] == 0 || y[j] == c);
		}

		if (cnt < 2) {
			continue;
		}

		for (int j = 0; j < 2; ++j) {
			if (x[j] == 0) {
				obj.emplace_back(y[j], i);	
			} else if (x[j] == r) {
				obj.emplace_back(c - y[j] + r + c, i);
			} else if (y[j] == c) {
				obj.emplace_back(c + x[j], i);
			} else if (y[j] == 0) {
				obj.emplace_back(r + c + c + r - x[j], i);
			}
		}
	}

	sort(obj.begin(), obj.end());
	vector<int> st;
	vector<int> vis(n);

	for (auto [p, c] : obj) {
		if (!vis[c]) {
			st.emplace_back(c);
			vis[c] = 1;
		} else {
			if (st.empty() || st.back() != c) {
				cout << "NO" << '\n';
				exit(0);
			} else {
				st.pop_back();
			}
		}
	}

	cout << "YES" << '\n';

	return 0;
}
