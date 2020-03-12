#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	string t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	int ans = 0;
	for(int i = 0; i < s.size(); ++i) {
		ans += s[i] != t[i];
	}
	cout << ans / 2 << '\n';
	return 0;
}
