#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int x = s.size() & 1;
	int y = *s.begin() == s.back();

	if(x ^ y) {
		cout << "First" << '\n';
	} else {
		cout << "Second" << '\n';
	}

	return 0;
}
