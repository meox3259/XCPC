#include <bits/stdc++.h>
using namespace std;
const int maxn = 65;
int n, m;
char s[maxn][maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", s[i] + 1);
		}
		bool f = 0, ff = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s[i][j] == 'A') {
					f = 1;
				}
				if(s[i][j] == 'P') {
					ff = 1;
				}
			}
		}
		if(!f) {
			puts("MORTAL");
			continue;
		}
		if(!ff) {
			puts("0");
			continue;
		}
		f = 1;
		for(int i = 1; i <= n; ++i) {
			if(s[i][1] != 'A') {
				f = 0;
				break;
			}
		}
		if(f) {
			puts("1");
			continue;
		}
		f = 1;
		for(int i = 1; i <= n; ++i) {
			if(s[i][m] != 'A') {
				f = 0;
				break;
			}
		}
		if(f) {
			puts("1");
			continue;
		}
		f = 1;
		for(int i = 1; i <= m; ++i) {
			if(s[1][i] != 'A') {
				f = 0;
				break;
			}
		}
		if(f) {
			puts("1");
			continue;
		}
		f = 1;
		for(int i = 1; i <= m; ++i) {
			if(s[n][i] != 'A') {
				f = 0;
				break;
			}
		}
		if(f) {
			puts("1");
			continue;
		}
		f = 0;
		for(int i = 1; i <= n; ++i) {
			bool t = 1;
			for(int j = 1; j <= m; ++j) {
				if(s[i][j] != 'A') {
					 t = 0;
					 break;
				}
			}
			if(t) {
				f = 1;
				break;
			}
		}
		if(f) {
			puts("2");
			continue;
		}
		for(int j = 1; j <= m; ++j) {
			bool t = 1;
			for(int i = 1; i <= n; ++i) {
				if(s[i][j] != 'A') {
					t = 0;
					break;
				}
			}
			if(t) {
				f = 1;
				break;
			}
		}
		if(f) {
			puts("2");
			continue;
		}
		if(s[1][1] == 'A' || s[n][1] == 'A' || s[1][m] == 'A' || s[n][m] == 'A') {
			puts("2");
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s[i][j] == 'A' && (i == 1 || i == n || j == 1 || j == m)) {
					f = 1;
					break;
				} 
			}
		}
		if(f) {
			puts("3");
			continue;
		}
		puts("4");
	}
	return 0;
}
