#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string s = "", t = "";
	for(int i = 0; i < b; ++i) {
		s += (char)(a + '0');
	}
	for(int i = 0; i < a; ++i) {
		t += (char)(b + '0');
	}
	cout << ((s < t) ? s : t) << endl;
	return 0;
}
