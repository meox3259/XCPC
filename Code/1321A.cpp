#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> r;
	vector<int> b;
	r.resize(n);
	b.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	int x = 0;
	int y = 0;
	for(int i = 0; i < n; ++i) {
		if(r[i] == 1 && b[i] == 0) {
			++x;
		}
		if(r[i] == 0 && b[i] == 1) {
			++y;
		}
	}
	if(x == 0) {
		cout << -1 << '\n';
	} else {
		cout << y / x + 1 << '\n';
	}
	return 0;
}
