#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char s[maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		bool f = 0;
		int p = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '0') {
				f = 1;
				p = i;
				break;
			}
		}
		if(!f) {
			puts("cyan");
			continue;
		}
		int sum = 0;
		f = 0;
		for(int i = 1; i <= n; ++i) {
			sum += s[i] - '0';
			if((s[i] - '0') % 2 == 0 && p != i) {
				f = 1;
			
			}
		}
		if(!f || sum % 3 != 0) {
			puts("cyan");
			continue;
		}
		puts("red");
	}
	return 0;
}
