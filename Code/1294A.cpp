#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; 
	cin >> T;
	while(T--) {
		int a, b, c, n, tot = 0;
		cin >> a >> b >> c >> n;
		tot = a + b + c + n;
		if(tot % 3 != 0) {
			puts("NO");
			continue;
		}
		tot /= 3;
		if(tot < a || tot < b || tot < c || tot - a > n || tot - b > n || tot - c > n) {
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
