#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i] --;
	}

	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		pos[p[i]] = i;	
	}

	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (ans.size() >= n) {
			break;
		}
		while (pos[i] > i) {
			ans.emplace_back(pos[i] - 1);
			int x = p[pos[i]];
			int y = p[pos[i] - 1];
			swap(p[pos[i]], p[pos[i] - 1]);
			swap(pos[x], pos[y]);
		}
	}

	set<int> s;
	for (int i : ans) {
		s.emplace(i);
	}

	if (ans.size() > n - 1 || s.size() != n - 1) {
		cout << -1 << '\n';
	} else {
		for (int i : ans) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}
