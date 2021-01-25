#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n;

	vector<vector<long long> > x(n, vector<long long> (2));
	for (int i = 0; i < n; ++i) {
		cin >> x[i][0] >> x[i][1];
	}

	cin >> m;

	vector<vector<pair<int, int> > > ask(m + 1);
	vector<pair<int, long long> > op;
	for (int i = 0; i < m; ++i) {
		int type;
		cin >> type;
		if (type == 1 || type == 2) {
			op.emplace_back(type, 0);
		} else {
			long long p;
			cin >> p;
			op.emplace_back(type, p);
		}
	}

	cin >> q;

	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		ask[a].emplace_back(b - 1, i);
	}

	vector<long long> add(2);
	vector<long long> tag(2, 1);
	vector<pair<long long, long long> > ans(q);
	int rev = 0;
	for (int i = 0; i <= m; ++i) {
		for (auto [v, o] : ask[i]) {
			ans[o] = make_pair(tag[0] * x[v][rev] + add[0], tag[1] * x[v][rev ^ 1] + add[1]);
		}
		if (i < m) {
			auto [type, p] = op[i];
			if (type == 1) {
				rev ^= 1;
				tag[0] *= -1;
				add[0] *= -1;
				swap(tag[0], tag[1]);
				swap(add[0], add[1]);
			} else if (type == 2) {
				rev ^= 1;
				tag[1] *= -1;
				add[1] *= -1;
				swap(tag[0], tag[1]);
				swap(add[0], add[1]);
			} else if (type == 3) {
				tag[0] *= -1;
				add[0] *= -1;
				add[0] += p + p;
			} else if(type == 4) {
				tag[1] *= -1;
				add[1] *= -1;
				add[1] += p + p;
			}
		}	
	}

	for (auto [X, Y] : ans) {
		cout << X << ' ' << Y << '\n';
	}

	return 0;
}
