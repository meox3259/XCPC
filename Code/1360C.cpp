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
		bool ok = true;
		int cnt = 0;
		for(int i : a) {
			if(i % 2 == 0) {
				cnt += 1;
			}
		}

		if(cnt % 2 == 1) {
			bool f = false;
			for(int i = 0; i < n; ++i) {
				if(a[i] % 2 == 0) {
					for(int j = 0; j < n; ++j) {
						if(a[j] % 2 == 1 && abs(a[i] - a[j]) == 1) {
							f = true;
						}
					}
				}
			}
			ok &= f;
		}

		if(ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
