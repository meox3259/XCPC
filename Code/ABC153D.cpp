#include <bits/stdc++.h>
using namespace std;
long long c(long long x) {
	if(x == 1) {
		return 1;
	}
	return 1 + c(x / 2) * 2;
}
int main() {
	long long h;
	cin >> h;
	cout << c(h);
	return 0;
}
