#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = 0;
	vector<vector<int> > a(n, vector<int>(m, 0));
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < m; ++j) {
			if(s[j] == '#') {
				a[i][j] = ++cnt;
				for(int k = j - 1; ~k; --k) {
					if(a[i][k] || s[k] == '#') {
						break;
					}
					a[i][k] = cnt;
				}
				for(int k = j + 1; k < m; ++k) {
					if(a[i][k] || s[k] == '#') {
						break;
					}
					a[i][k] = cnt;
				}
			}
		}
	}
	cout << '\n';
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			if(!a[i][j]) {
				continue;
			}
			for(int k = i - 1; ~k; --k) {
				if(a[k][j]) {
					break;
				}
				a[k][j] = a[i][j];
			}
			for(int k = i + 1; k < n; ++k) {
				if(a[k][j]) {
					break;
				}
				a[k][j] = a[i][j];
			}
		}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
