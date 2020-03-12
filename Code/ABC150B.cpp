#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n - 2; ++i) {
		if(s.substr(i, 3) == "ABC") {
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
