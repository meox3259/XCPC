#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; 
	cin >> T;
	while(T--) {
		long long x, y;
		cin >> x >> y;
		x -= y;
		puts(x == 1 ? "NO" : "YES");
	}
	return 0;
}
