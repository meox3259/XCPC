#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<bitset<maxn> > v(n);
	for(int i = 1; i < n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < i; ++j) {
			if(s[j] == '1') {
				v[i][j] = 1;
			} else {
				v[j][i] = 1;
			}
		}
	}
	vector<bitset<maxn> > l(n);
	vector<bitset<maxn> > r(n);
	for(int i = 0; i < n; ++i) {
		l[i][i] = r[i][i] = 1;
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 0; i + j < n; ++j) {
			l[i + j][j] = (l[i + j] & r[j + 1] & v[j]).any();
			r[j][i + j] = (r[j] & l[i + j - 1] & v[i + j]).any();
		}
	}
	cout << (r[0] & l[n - 1]).count() << '\n';
	return 0;
}
