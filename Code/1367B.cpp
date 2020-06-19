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

		int cnt0 = 0;
		int cnt1 = 0;

		for(int i = 0; i < n; ++i) {
			if(i % 2 != a[i] % 2) {
				if(i % 2 == 0) {
					cnt0 += 1;
				} else {
					cnt1 += 1;
				}
			}
		}

		if(cnt0 != cnt1) {
			cout << -1 << '\n';
		} else {
			cout << cnt0 << '\n';
		}
	}

	return 0;
}
