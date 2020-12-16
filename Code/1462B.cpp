#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int cnt = 0;
		string a = s.substr(0, 2) + s.substr(n - 2, 2);
		string b = s.substr(0, 4);
		string c = s.substr(n - 4, 4);
		string d = s.substr(0, 1) + s.substr(n - 3, 3);
		string e = s.substr(0, 3) + s.substr(n - 1, 1);
		if (a == "2020" || b == "2020" || c == "2020" || d == "2020" || e == "2020") {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
