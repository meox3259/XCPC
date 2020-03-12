#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, L, R;
int ans[maxn];
int Ask(int l, int r) {
	cout << '?';
	for(int i = l; i <= r; ++i) {
		cout << ' ' << i;
	}
	cout << '\n';
	string ret;
	cin >> ret;
	return ret == "Red" ? -1 : 1; 
}
int Ask(int x) {
	cout << '?' << ' ' << x;
	for(int i = 1; i <= 2 * n; ++i) {
		if(i != L && i != R && (L < i && i < R) != (L < x && x < R)) {
			cout << ' ' << i;
		}
	}
	cout << '\n';
	string ret;
	cin >> ret;
	return ret == "Red" ? -1 : 1;
}
int main() {
	cin >> n;
	int prv = Ask(1, n);
	int l = 1, r = n + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(Ask(mid, mid + n - 1) == prv) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ans[l] = prv;
	ans[l + n] = -prv;
	L = l;
	R = l + n;
	for(int i = 1; i <= 2 * n; ++i) {
		if(i != L && i != R) {
			ans[i] = Ask(i);
		}
	}
	cout << "! ";
	for(int i = 1; i <= 2 * n; ++i) {
		cout << (ans[i] == -1 ? 'R' : 'B');
	}
	cout << '\n';
	return 0;
}
