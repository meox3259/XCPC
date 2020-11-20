#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int x, k, y;
	cin >> x >> k >> y;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	for(int i = 0; i < n; ++i) {
		a[i] -= 1;
	}

	for(int i = 0; i < m; ++i) {
		b[i] -= 1;
	}

	vector<int> mir(n);
	for(int i = 0; i < n; ++i) {
		mir[a[i]] = i;
	}

	bool ok = true;
	for(int i = 0; i + 1 < m; ++i) {
		if(mir[b[i + 1]] < mir[b[i]]) {
			ok = false;
		}
	}

	auto solve = [&] (vector<int> a, int mx) {
		if(a.empty()) {
			return 0LL;
		}
		cerr << "begin" << '\n';
		for(int i : a) {
			cerr << i << ' ';
		}
		cerr << '\n';
		if(a.size() < k) {
			if(*max_element(a.begin(), a.end()) > mx) {
				ok = false;
				cout << -1 << '\n';
				exit(0);
			}
		}
		int d = a.size() / k;
		int m = a.size();
		if(1LL * k * y >= x) {
			return 1LL * x * d + 1LL * y * (m % k);
		} else {
			if(*max_element(a.begin(), a.end()) < mx) {
				return 1LL * y * m;
			} else {
				return 1LL * (m - k) * y + x;
			}
		}
		return 0LL;
	};

	long long ans = 0;

	vector<int> tmp;
	for(int i = 0; i < mir[b[0]]; ++i) {
		tmp.emplace_back(a[i]);
	}

	ans += solve(tmp, b[0]);

	tmp.clear();
	for(int i = mir[b.back()] + 1; i < n; ++i) {
		tmp.emplace_back(a[i]);
	}

	ans += solve(tmp, b.back());

	for(int i = 0; i + 1 < m; ++i) {
		tmp.clear();
		for(int j = mir[b[i]] + 1; j < mir[b[i + 1]]; ++j) {
			tmp.emplace_back(a[j]);
		}
		ans += solve(tmp, max(b[i], b[i + 1]));
	}

	if(!ok) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
