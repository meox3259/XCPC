#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			b[i] = s[i] - '0';
		}

		int pre = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j >= 0; --j) {
				if ((b[i] + j) != pre) {
					pre = b[i] + j;
					cout << j;
					break;
				}
			}
		}

		cout << '\n';
	}

	return 0;
}
