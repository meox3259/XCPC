#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; 
	cin >> T;
	while(T--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		string t = "";
		for(int i = 1; i < k; ++i) {
			t = t + "()";
		}
		t = t + '(';
		for(int i = 1; i <= n / 2 - k; ++i) {
			t = t + "()";
		}
		t = t + ')';
		cout << n << '\n';
		for(int i = 0; i < n; ++i) {
			for(int j = i; j < n; ++j) {
				if(t[i] == s[j]) {
					for(int k = i; k * 2 < i + j; ++k) {
						swap(s[k], s[i + j - k]);
					}
					cout << i + 1 << " " << j + 1 << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
