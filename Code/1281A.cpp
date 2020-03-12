#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int T; cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size() - 1;
		if(s.size() >= 2 && s[n - 1] == 'p' && s[n] == 'o') {
			puts("FILIPINO");
			continue;
		}
		if(s.size() >= 4 && ((s[n - 3] == 'd' && s[n - 2] == 'e' && s[n - 1] == 's' && s[n] == 'u') || (s[n - 3] == 'm' && s[n - 2] == 'a' && s[n - 1] == 's' && s[n] == 'u'))) {
			puts("JAPANESE");
			continue;
		}
		if(s.size() >= 5 && s[n - 4] == 'm' && s[n - 3] == 'n' && s[n - 2] == 'i' && s[n - 1] == 'd' && s[n] == 'a') {
			puts("KOREAN");
			continue;
		}
	}
	return 0;
}
