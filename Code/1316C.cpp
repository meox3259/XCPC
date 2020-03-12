#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
int main() {
	int n = read(), m = read(), p = read();
	vector<int> a;
	vector<int> b;
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < n; ++i) {
		a[i] = read();
	}
	for(int i = 0; i < m; ++i) {
		b[i] = read();
	}
	int x = 0, y = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] % p != 0) {
			x = i;
			break;
		}
	}
	for(int i = 0; i < m; ++i) {
		if(b[i] % p != 0) {
			y = i;
			break;
		}
	}
	cout << x + y << '\n';
	return 0;
}
