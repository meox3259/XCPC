#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	vector<int> cnt(N + 1);

	while (T --) {
		int n;
		cin >> n;

		vector<int> a(n + n);
		for (int i = 0; i < n + n; ++i) {
			cin >> a[i];
		}

		for (int i : a) {
			cnt[i] ++;
		}

		sort(a.begin(), a.end());

		bool flag = false;
		for (int d = 0; d < n + n - 1; ++d) {
			int x = a[n + n - 1] + a[d];
			int i = n + n - 1;
			bool ok = true;
			vector<pair<int, int> > ans;
			vector<int> tmp;
			for (int _ = 0; _ < n; ++_) {
				while (i >= 0 && cnt[a[i]] == 0) {
					i --;
				}
				if (i < 0) {
					ok = false;
					break;
				}

				cnt[a[i]] --;
				tmp.emplace_back(a[i]);
				if (cnt[x - a[i]] <= 0) {
					ok = false;
					break;
				}

				tmp.emplace_back(x - a[i]);
				cnt[x - a[i]] --;

				ans.emplace_back(a[i], x - a[i]);
				x = a[i];
			}

			for (int i : tmp) {
				cnt[i] ++;
			}

			if (ok) {
				cout << "YES" << '\n';
				cout << a[n + n - 1] + a[d] << '\n';
				for (auto [x, y] : ans) {
					cout << x << ' ' << y << '\n';
				}
				flag = true;
				break;
			}
		}

		for (int i : a){
			cnt[i] --;
		}

		if (!flag) {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
