#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m, s;
int a[maxn][10], mn[maxn][251 + 10], id[maxn];
bool C(int x) {
	for(int i = 0; i < s; ++i) {
		id[i] = 0;
	}
	for(int i = 0; i < s; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(mn[j][i] >= x) {
				id[i] = j;
				break;
			}
		}
	}
	if(id[s - 1]) {
		return 1;
	}
	for(int i = 0; i < s; ++i) {
		if(id[i] && id[(s - 1) ^ i]) {
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	s = 1 << m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(mn, 0x3f3f, sizeof(mn));
	for(int S = 0; S < s; ++S) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(S >> j & 1) {
					mn[i][S] = min(mn[i][S], a[i][j]);
				}
			}
		}
	}
	for(int S = 0; S < s; ++S) {
		int val = 0;
		for(int i = 1; i <= n; ++i) {
			val = max(val, mn[i][S]);
		}
		for(int i = 1; i <= n; ++i) {
			if(mn[i][S] == val) {
				id[S] = i;
				break;
			}
		}
	}
	int val = 0;
	for(int i = 0; i < s; ++i) {
		val = max(val, min(mn[id[i]][i], mn[id[(s - 1) ^ i]][(s - 1) ^ i]));
	}
	for(int i = 0; i < s; ++i) {
		if(val == min(mn[id[i]][i], mn[id[(s - 1) ^ i]][(s - 1) ^ i])) {
		//	if(i && i != s - 1) {
				printf("%d %d\n", id[i], id[(s - 1) ^ i]);
		/*	} else {
				if(id[i]) {
					printf("%d %d\n", id[i], id[i]);
				} else {
					printf("%d %d\n", id[(s - 1) ^ i], id[(s - 1) ^ i]);
				}
			}
			return 0;
		} */
		return 0;}
	}
	return 0;
}
