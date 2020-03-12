#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool f = 1;
		for(int i = 0; i < n; ++i) {
			if(c[i] != a[i] && c[i] != b[i]) {
				f = 0;
				break;
			}
		}
		if(f) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
