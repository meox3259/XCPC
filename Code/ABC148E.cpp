#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
	if(n & 1) {
		cout << 0 << '\n';
		return 0;
	}
	long long x = 0;
	long long t = n;
	while(t) {
		x += t / 10;
		t /= 5;
	}
	cout << x << '\n';
	return 0;
}
