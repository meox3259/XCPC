#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	for(auto c = 'z'; c >= 'a'; --c) {
		for(int T = 100; T > 0; --T) {
			for(int i = 0; i < s.size(); ++i) {
				if(s[i] == c && ((i > 0 && s[i - 1] == s[i] - 1) || (i < (int)s.size() - 1 && s[i + 1] == s[i] - 1))) {
					s.erase(i, 1);
					break;
				}
			}
		}
	}
	cout << n - s.size() << '\n';
	return 0;
}
