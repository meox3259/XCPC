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

		reverse(s.begin(), s.end());
		while (!s.empty() && s.back() != '8') {
			s.pop_back();
		}

		if (s.size() >= 11) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
