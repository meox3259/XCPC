#include <bits/stdc++.h>
using namespace std;
int main() {
	string s, t, p;
	int a, b;
	cin >> s >> t >> a >> b >> p;
	if(p == s) {
		--a;
	}
	if(p == t) {
		--b;
	}
	cout << a << ' ' << b << '\n';
	return 0;
}
