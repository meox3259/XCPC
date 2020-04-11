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

		vector<int> p(n);
		vector<int> c(n);

		for(int i = 0; i < n; ++i) {
			cin >> p[i] >> c[i];
		}

		bool ok = true;

		if(p[0] < c[0]) {
			ok = false;
		}

		for(int i = 0; i < n - 1; ++i) {
			if(p[i + 1] - p[i] < c[i + 1] - c[i]) {
				ok = false;
			}

			if(p[i + 1] < p[i] || c[i + 1] < c[i]) {
				ok = false;
			}
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
