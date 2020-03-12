#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		if(n % m == 0) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
