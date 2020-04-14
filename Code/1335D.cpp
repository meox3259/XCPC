#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		vector<vector<int> > a;
		a.resize(9);

		for(int i = 0; i < 9; ++i) {
			a[i].resize(9);
		}

		for(int i = 0; i < 9; ++i) {
			string s;
			cin >> s;

			for(int j = 0; j < 9; ++j) {
				a[i][j] = s[j] - '0';
			}
		}

		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				bool ok = false;
				for(int x = 0; x < 3; ++x) {
					for(int y = 0; y < 3; ++y) {
						if(a[3 * i + x][3 * j + y] == 1) {
							a[3 * i + (x + 1) % 3][3 * j + y] = 1;
							ok = true;
							break;
						}
					}

					if(ok) {
						break;
					}
				}
			}
		}

		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				cout << a[i][j];
			}

			cout << '\n';
		}
	}

	return 0;
}
