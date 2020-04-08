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

		vector<int> a(n + 1);
		vector<int> b(n + 1);

		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		for(int i = 1; i <= n; ++i) {
			cin >> b[i];
		}

		vector<int> p1(n + 1, 0);
		vector<int> p2(n + 1, 0);

		for(int i = 1; i <= n; ++i) {
			if(a[i] == -1) {
				++p1[i];
			} 

			if(a[i] == 1) {
				++p2[i];
			}

			p1[i] += p1[i - 1];
			p2[i] += p2[i - 1];
		}

		bool ok = true;

		for(int i = n; i >= 1; --i) {
			if(a[i] != b[i]) {
				if(a[i] < b[i]) {
					if(p2[i - 1] == 0) {
						ok = false;
					}
				}

				if(a[i] > b[i]) {
					if(p1[i - 1] == 0) {
						ok = false;
					}
				}
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
