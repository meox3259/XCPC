#include <bits/stdc++.h>
using namespace std;
int n;
string End;
string s[55];
int t[55];
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i] >> t[i];
	}
	cin >> End;
	int ans = 0;
	for(int i = n; i; --i) {
		if(s[i] == End) {
			break;
		}
		ans += t[i];
	}
	cout << ans;
	return 0;
}
