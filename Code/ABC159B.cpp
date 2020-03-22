#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();

	string x = s.substr(0, (n - 1) / 2);
	string y = s.substr((n + 3) / 2 - 1, n - (n + 3) / 2 + 1);

	auto same = [&] (string s) {
		string t = s;
		reverse(t.begin(), t.end());
		return s == t;
	};

	if(same(s) && same(x) && same(y)) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
	return 0;
}
