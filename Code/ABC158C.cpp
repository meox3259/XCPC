#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	a = a * 100;
	b = b * 100;
	for(int i = 0; i <= 100000; ++i) {
		if(i * 8 - (i * 8) % 100 == a && i * 10 - (i * 10) % 100 == b) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
