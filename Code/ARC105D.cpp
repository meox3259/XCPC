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

		if(n & 1) {
			sort(a.begin(), a.end());
			// 1 是后手
			cout << "Second" << '\n';
		} else {
			sort(a.begin(), a.end());
			bool ok = true;
			for(int i = 0; i < n; i += 2) {
				if(a[i] != a[i + 1]) {
					ok = false;
				}
			}
			if(ok) {
				cout << "Second" << '\n'; 
			} else {
				cout << "First" << '\n';
			}
		}
	}

	return 0;
}
