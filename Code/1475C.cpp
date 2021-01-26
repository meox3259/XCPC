#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> a(k);
		vector<int> b(k);
		for (int i = 0; i < k; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < k; ++i) {
			cin >> b[i];
		}

		map<int, int> cnta;
		map<int, int> cntb;
		map<pair<int, int>, int> cntc;
		long long ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += i - (cnta[a[i]] + cntb[b[i]] - cntc[{a[i], b[i]}]);
			cnta[a[i]] ++;
			cntb[b[i]] ++;
			cntc[{a[i], b[i]}] ++;
		}

		cout << ans << '\n';
	}

	return 0;
}
