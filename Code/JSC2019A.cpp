#include <bits/stdc++.h>
using namespace std;
int main() {
	int m, d;
	cin >> m >> d;
	int ans = 0;
	for(int i = 2; i < 10; ++i) {
		for(int j = 2; j < 10; ++j) {
			if(i * 10 + j <= d && i * j <= m) {
				++ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
