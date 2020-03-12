#include <bits/stdc++.h>
using namespace std;
int n;
string s, ans;
int cnt[105][30];
int main() {
	cin >> n;
	cout << "? " << 1 << " " << n << endl;
	for(int i = 1; i <= n * (n + 1) / 2; ++i) {
		cin >> s;
		for(auto c : s) {
			++cnt[s.length()][c - 'a'];
		}
	}
	if(n > 1) {
		cout << "? " << 2 << " " << n << endl;
	}
	for(int i = 1; i <= n * (n - 1) / 2; ++i) {
		cin >> s;
		for(auto c : s) {
			--cnt[s.length()][c - 'a'];
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j) {
			if(cnt[i][j]) {
				ans += 'a' + j;
				for(int k = i + 1; k <= n; ++k) {
					--cnt[k][j];
				}
			}
		}
	}
	cout << "! " << ans << endl; 
	return 0;
}

