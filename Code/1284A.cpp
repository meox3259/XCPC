#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[105], t[105];
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	int q; cin >> q;
	while(q--) {
		int x; cin >> x;
		--x;
		cout << s[x % n];
		cout << t[x % m] << endl;
	}
	return 0;
}
