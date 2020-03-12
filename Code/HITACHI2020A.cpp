#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	if(n % 2 == 1) {
		cout << "No" << '\n';
		return 0;
	}
	string t = "";
	for(int i = 0; i < n / 2; ++i) {
		t += "hi";
	}
	if(s == t) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
	return 0;
}
