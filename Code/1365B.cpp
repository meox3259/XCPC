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
		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		bool zero = false;
		bool one = false;
		for(int i : b) {
			if(i == 0) {
				zero = true;
			}
			if(i == 1) {
				one = true;
			}
		}
		if(zero && one) {
			cout << "Yes" << '\n';
			continue;
		}
		int cur0 = 0;
		int cur1 = 0;
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			if(b[i] == 0) {
				if(a[i] < cur0) {
					ok = false;
				}
				cur0 = max(cur0, a[i]);
			}
			if(b[i] == 1) {
				if(a[i] < cur1) {
					ok = false;
				}
				cur1 = max(cur1, a[i]);
			}
		}
		if(ok) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
