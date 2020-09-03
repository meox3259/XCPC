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

		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		int ma = *min_element(a.begin(), a.end());
		int mb = *min_element(b.begin(), b.end());

		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			int da = a[i] - ma;
			int db = b[i] - mb;
			ans += min(da, db);
			ans += da + db - 2LL * min(da, db);
		}

		cout << ans << '\n';
	}

	return 0;
}


