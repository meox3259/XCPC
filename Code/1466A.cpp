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

		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}

		set<int> s;

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				s.emplace(x[j] - x[i]);
			}
		}

		cout << s.size() << '\n';
	}

	return 0;
}
