#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a;
	string s;
	cin >> a >> s;
	long long b = 0;
	for(char c : s) {
		if(isdigit(c)) {
			b = b * 10 + c - '0';
		}
	}
	cout << a * b / 100 << '\n';
	return 0;
}
