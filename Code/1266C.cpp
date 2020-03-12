#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int r, c;
int a[505][505], p[maxn], mark[maxn];
int main() {
	for(int i = 2; i <= 100000; ++i) {
		if(!mark[i]) {
			p[++p[0]] = i;
		}	
		for(int j = 1; j <= p[0] && i * p[j] <= 100000; ++j) {
			mark[i * p[j]] = 1;
			if(i % p[j] == 0) {
				break;
			}
		}
	}	
	p[0] = 1;
	scanf("%d%d", &r, &c);
	if(r == 1 && c == 1) {
		puts("0");
		return 0;
	}
	if(c == 1) {
		for(int i = 1; i <= r; ++i) a[i][1] = i + 1;
		for(int i = 1; i <= r; ++i) {
			for(int j = 1; j <= c; ++j) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}
		return 0;
	}
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			a[i][j] = 1;
		}
	}
	int d = 0;
	for(int i = 1; i <= r; ++i) {
		++d;
		for(int j = 1; j <= c; ++j) {
			a[i][j] *= d; 
		}
	}
	for(int i = 1; i <= c; ++i) {
		++d;
		for(int j = 1; j <= r; ++j) {
			a[j][i] *= d;
		}
	}
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}
