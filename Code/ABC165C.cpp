#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> a(q);
	vector<int> b(q);
	vector<int> c(q);
	vector<int> d(q);

	for(int i = 0; i < q; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> A(n);

	int ans = 0;

	function<void(int, int)> dfs = [&] (int p, int low) {
		if(p == n) {
			int tot = 0;
			for(int i = 0; i < q; ++i) {
				tot += (A[b[i] - 1] - A[a[i] - 1] == c[i]) * d[i];
			}
			ans = max(ans, tot);
			return;
		}

		for(int i = low; i <= m; ++i) {
			A[p] = i;
			dfs(p + 1, i);
			A[p] = 0;
		}
	};

	dfs(0, 1);

	cout << ans << '\n';

	return 0;
}
