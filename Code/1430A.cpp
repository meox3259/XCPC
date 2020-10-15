#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	vector<pair<int, int> > a(1001, {-1, -1});
	for(int i = 0; i * 3 <= 1000; ++i) {
		for(int j = 0; j * 5 + i * 3 <= 1000; ++j) {
			a[i * 3 + j * 5] = {i, j};
		}
	}

	while(T--) {
		int n;
		cin >> n;

		bool ok = false;
		for(int i = 0; i <= n; i += 7) {
			if(a[n - i].first != -1) {
				ok = true;
				cout << a[n - i].first << ' ' << a[n - i].second << ' ' << i / 7 << '\n';
				break;
			}
		}

		if(!ok) {
			cout << -1 << '\n';
		}
	}

	return 0;
}
