#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, q;
int s[maxn][30];
char S[maxn];
int main() {
	scanf("%s", S + 1);
	n = strlen(S + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j) {
			s[i][j] = s[i - 1][j];
		}
		++s[i][S[i] - 'a'];
	}
	scanf("%d", &q);
	while(q--) {
	int l, r;
		scanf("%d%d", &l, &r);
		if(l == r) {
			puts("Yes");
			continue;
		}
		int c = 0, mx = 0;
		for(int i = 0; i < 26; ++i) {
			if(s[r][i] - s[l - 1][i] > 0) {
				++c;
				mx = max(mx, s[r][i] - s[l - 1][i]);
			} 
		}
		if(c == 1) {
			puts("No");
		} else {
			if(c == 2 && S[l] == S[r]) {
				puts("No");
			} else {
				puts("Yes");
			}
		}
	}
	return 0;
}
