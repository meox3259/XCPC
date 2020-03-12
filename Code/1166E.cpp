#include <bits/stdc++.h>
using namespace std;
int n, m;
bitset<10005> s[55];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		for(int j = 1; j <= x; ++j) {
			int p;
			cin >> p;
			s[i][p] = 1;
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = i + 1; j <= m; ++j) {
			if(!(s[i] & s[j]).count()) {
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible"); 
	return 0;
}
