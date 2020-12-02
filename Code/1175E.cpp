#include <bits/stdc++.h>

using namespace std;

const int N = 500001;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> nxt(N + 1);
	iota(nxt.begin(), nxt.end(), 0);
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		nxt[l] = max(nxt[l], r);
	}

	for (int i = 0; i < N; ++i) {
		nxt[i + 1] = max(nxt[i + 1], nxt[i]);
	}

	vector<vector<int> > jump(N, vector<int> (23));
	for (int i = 0; i < N; ++i) {
		jump[i][0] = nxt[i];
	}
	for (int j = 0; j < 22; ++j) {
		for (int i = 0; i < N; ++i) {
			jump[i][j + 1] = jump[jump[i][j]][j];
		}
	}

	while (m--) {
		int x, y;
		cin >> x >> y;

		int ans = 0;
		for (int i = 22; i >= 0; --i) {
			if (jump[x][i] < y) {
				x = jump[x][i];
				ans += 1 << i;
			}	
		}

		x = jump[x][0];

		if (x < y) {
			cout << -1 << '\n';
		} else {
			cout << ans + 1 << '\n';
		}
	}

	return 0;
}
