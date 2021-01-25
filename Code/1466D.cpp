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

		vector<int> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}

		vector<vector<int> > adj(n);
		vector<int> deg(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y;
			x --;
			y --;
			deg[x] ++;
			deg[y] ++;
		}

		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += w[i];
		}

		priority_queue<int> q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < deg[i] - 1; ++j) {
				q.emplace(w[i]);
			}
		}

		for (int i = 0; i < n - 1; ++i) {
			cout << sum << " \n"[i == n - 2];
			if (!q.empty()) {
				sum += q.top();
				q.pop();
			}
		}
	}

	return 0;
}
