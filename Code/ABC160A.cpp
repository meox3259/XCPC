#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	if(s[2] == s[3] && s[4] == s[5]) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
