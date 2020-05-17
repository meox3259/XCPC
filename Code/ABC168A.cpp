#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int c = s.back() - '0';

	if(c == 3) {
		cout << "bon" << '\n';
	} else if(c == 0 || c == 1 || c == 6 || c == 8) {
		cout << "pon" << '\n';
	} else {
		cout << "hon" << '\n';
	}

	return 0;
}
