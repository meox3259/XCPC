#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int f = 0, a = n, b = -1, c = -1;
		for(int i = 2; i * i <= n; ++i) {
			if(n % i == 0) {
				int t = n / i;
				for(int j = 2; j * j <= t; ++j) {
					if(t % j == 0) {
						if(i != j && i != t / j && j * j != t) {
							a = i;
							b = j;
							c = t / j;
							f = 1;
							break;
						}
					}
					if(f) {
						break;
					}
				}
			}
			if(f) {
				break;
			}
		}
		if(!f) {
			puts("NO");
		} else {
			puts("YES");
			printf("%d %d %d\n", a, b, c);
		}
	}
	return 0;
}
