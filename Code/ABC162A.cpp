#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;

	bool ok = false;

	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '7') {
			ok = true;
		}
	}

	if(ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
