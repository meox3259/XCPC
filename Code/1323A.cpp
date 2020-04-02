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

		vector<int> a;
		a.resize(n);

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		bool ok = false;

		int x = -1;

		for(int i = 0; i < n; ++i) {
			if(a[i] % 2 == 0) {
				ok = true;
				x = i;
			}
		}

		if(ok == true) {
			cout << 1 << '\n';
			cout << x + 1 << '\n';
		} else if(ok == false && a.size() == 1) {
			cout << -1 << '\n';
		} else {
			cout << 2 << '\n';
			cout << 1 << ' ' << 2 << '\n';
		}
	}

	return 0;
}
