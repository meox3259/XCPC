#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, s;
		cin >> n >> s;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int mx = 0;
		int cur = -1;
		int sum = 0;
		bool ok = false;

		for(int i = 0; i < n; ++i) {
			if(mx < a[i]) {
				cur = i;
				mx = a[i];
			}
			if(sum + a[i] > s) {
				ok = true;
				break;
			} else {
				sum = sum + a[i];
			}
		}

		if(ok) {
			cout << cur + 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}

	return 0;
}
