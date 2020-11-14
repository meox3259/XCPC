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

		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		sort(b.begin(), b.end());
		
		bool ok = false;
		for(int i = 0; i + 1 < n; ++i) {
			if(b[i] == b[i + 1]) {
				ok = true;
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
