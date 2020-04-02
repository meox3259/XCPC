#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while(q--) {
		int n;
		cin >> n;

		vector<int> t;
		t.resize(n);

		for(int i = 0; i < n; ++i) {
			cin >> t[i];
		}

		bool dif = false;

		int p = -1;

		for(int i = 0; i < n; ++i) {
			if(t[i] != t[(i + 1) % n]) {
				dif = true;
			}
		}

		if(!dif) {
			cout << 1 << '\n';

			for(int i = 0; i < n; ++i) {
				cout << 1 << ' ';
			}

			cout << '\n';
		} else {
			if(n % 2 == 0) {
				cout << 2 << '\n';

				for(int i = 0; i < n; ++i) {
					cout << (i & 1) + 1 << ' ';
				}

				cout << '\n';
			} else {
				bool adj = false;
				int p = -1;

				for(int i = 0; i < n; ++i) {
					if(t[i] == t[(i + 1) % n]) {
						adj = true;
						p = i;
						break;
					}
				}

				if(adj) {
					cout << 2 << '\n';
					for(int i = 0; i < n; ++i) {
						if(i <= p) {
							cout << (i & 1) + 1 << ' ';
						} else {
							cout << ((i & 1) ^ 1) + 1 << ' ';
						}
					}

					cout << '\n';
				} else {
					cout << 3 << '\n';

					for(int i = 0; i < n - 1; ++i) {
						cout << i % 2 + 1 << ' ' ;
					}

					cout << 3 << '\n';
				}
			}
		}


	}

	return 0;
}
