#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<vector<int> > a;
	vector<vector<int> > c;
	a.resize(3);
	c.resize(3);
	for(int i = 0; i < 3; ++i) {
		a[i].resize(3);
		c[i].resize(3);
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;
	vector<int> b;
	b.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			for(int k = 0; k < n; ++k) {
				if(a[i][j] == b[k]) {
					c[i][j] = 1;
				}
			}
		}
	}
	for(int i = 0; i < 3; ++i) {
		bool f = 1;
		for(int j = 0; j < 3; ++j) {
			if(c[i][j] == 0) {
				f = 0;
			}
		}
		if(f == 1) {
			cout << "Yes" << '\n';
			return 0;
		}
		f = 1;
		for(int j = 0; j < 3; ++j) {
			if(c[j][i] == 0) {
				f = 0;
			}
		}
		if(f == 1) {
			cout << "Yes" << '\n';
			return 0;
		}
	}
	bool f = 1;
	for(int i = 0; i < 3; ++i) {
		if(c[i][i] == 0) {
			f = 0;
		}
	}
	if(f == 1) {
		cout << "Yes" << '\n';
		return 0;
	}
	f = 1;
	for(int i = 0; i < 3; ++i) {
		if(c[i][2 - i] == 0) {
			f = 0;
		}
	}
	if(f == 1) {
		cout << "Yes" << '\n';
		return 0;
	}
	cout << "No" << '\n';
	return 0;
}
