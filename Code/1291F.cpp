#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, K;
	cin >> n >> K;

	int t = (K + 1) / 2;

	vector<bool> vis;
	vis.resize(n + 1);

	for(int i = 1; i <= t; ++i) {
		cout << '?' << ' ' << i << '\n';

		char c;
		cin >> c;

		if(c == 'Y') {
			vis[i] = true;
		}
	}

	cout << 'R' << '\n';

	for(int i = t + 1; i <= n; i += t) {
		for(int j = 1; j < i; j += t) {
			for(int k = i; k <= min(n, i + t - 1); ++k) {
				cout << '?' << ' ' << k << '\n';

				char c;
				cin >> c;

				if(c == 'Y') {
					vis[k] = true;
				}
			}

			for(int k = 0; k < t; ++k) {
				if(!vis[j + k]) {
					cout << '?' << ' ' << j + k << '\n';

					char c;
					cin >> c;

					if(c == 'Y') {
						vis[j + k] = true;
					}
				}
			}

			cout << 'R' << '\n'; 
		}
	}

	int ans = n;

	for(auto x : vis) {
		if(x) {
			--ans;
		}
	}

	cout << '!' << ' ' << ans << '\n';

	return 0;
}
