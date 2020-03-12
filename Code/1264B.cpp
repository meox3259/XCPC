#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a, b, c, d;
int st[maxn], x[maxn];
bool solve(int a, int b, int c, int d) {
	int p = 0, t = 0, ma = a, mb = b, mc = c, md = d;
	if(c == 0 && d == 0) {
		if(abs(a - b) > 1) {
			return false;
		}
		int top = 0;
		if(a >= b) {
			for(int i = 1; i <= a; ++i) {
				st[++top] = 0;
				st[++top] = 1; 
			}
			if(a > b) st[++top] = 0;
			return true;
		} else {
			st[++top] = 1;
			for(int i = 1; i <= a; ++i) {
				st[++top] = 0;
				st[++top] = 1; 
			}
			return true;
		}
	}
	for(int s = 0; s < 2; ++s) {
		int top = 0;
		a = ma;
		b = mb;
		c = mc;
		d = md;
		if(s == 1) {
			--b;
			st[++top] = 1;
		}
		int ta = a;
		for(int i = 1; i <= ta; ++i) {
			st[++top] = 0;
			st[++top] = 1;
			--a;
			--b;
		}
		if(a != 0 || b < 0) continue;
		int tb = b;
		for(int i = 1; i <= tb; ++i) {
			st[++top] = 2;
			st[++top] = 1;
			--b;
			--c;
		}
		--c;
		st[++top] = 2;
		if(b != 0 || c < 0) continue;
		int tc = c;
		for(int i = 1; i <= tc; ++i) {
			st[++top] = 3;
			st[++top] = 2;
			--c;
			--d;
		}
		if(d) {
			--d;
			st[++top] = 3; 
		}
		if(c != 0 || d != 0) continue;
		return true;
	}
	return false;
}
int main() {
	cin >> a >> b >> c >> d;
	int n = a + b + c + d;
	if(n == 1) {
		puts("YES");
		if(a) puts("0");
		if(b) puts("1");
		if(c) puts("2");
		if(d) puts("3");
		return 0;
	}
	int cnt = (a != 0) + (b != 0) + (c != 0) + (d != 0);
	if(cnt == 1) {
		if(n > 1) {
			puts("NO");
			return 0;
		}
	}
	if(solve(a, b, c, d)) {
		puts("YES");
		for(int i = 1; i <= n; ++i) printf("%d ", st[i]);
		return 0;
	}
	if(solve(d, c, b, a)) {
		x[0] = 3;
		x[1] = 2;
		x[2] = 1;
		x[3] = 0;
		puts("YES");
		for(int i = 1; i <= n; ++i) printf("%d ", x[st[i]]);
		return 0;
	}
	puts("NO");
	return 0;
}
