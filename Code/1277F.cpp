#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n, m, mx, row, col;
int a[maxn], cnt[maxn], c[maxn], b[maxn], id[maxn];
bool cmp(int i, int j) {
	return cnt[i] > cnt[j];
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] != a[i - 1]) {
			a[++m] = a[i];
		} 
		++cnt[m];
	}
	for(int i = 1; i <= m; ++i) {
		++c[cnt[i]];
	}
	int sum = 0, remain = m;
	for(int i = 1; i * i <= n; ++i) {
		sum += i * c[i];
		remain -= c[i];
		int tot = sum + remain * i;
		if(tot < i * i) {
			continue;
		}
		if(tot / i * i > mx) {
			mx = tot / i * i;
			row = i;
			col = tot / i;
		}
	}
	for(int i = 1; i <= m; ++i) {
		id[i] = i;
	}
	sort(id + 1, id + m + 1, cmp);
	int x = 1, y = 1;
	for(int i = 1; i <= m; ++i) {
		int tot = min(cnt[id[i]], row);
		while(tot--) {
			b[(x - 1) * col + y] = a[id[i]];
			x = (x % row) + 1;
			y = (y % col) + 1;
			if(b[(x - 1) * col + y]) {
				y = (y % col) + 1;
			}
		}
	}
	printf("%d\n%d %d\n", mx, row, col);
	for(int i = 1; i <= row; ++i) {
		for(int j = 1; j <= col; ++j) {
			printf("%d ", b[(i - 1) * col + j]);
		}
		puts("");
	}
	return 0;
}
