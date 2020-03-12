#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		if(s < t) {
			cout << s << '\n';
			continue;
		}
		int n = s.size();
		bool f = 0;
		for(int i = 0; i < n; ++i) {
			int p = i;
			for(int j = i + 1; j < n; ++j) {
				if(s[j] <= s[p]) {
					p = j;
				}
			}
			swap(s[i], s[p]);
			if(s < t) {
				cout << s << '\n';
				f = 1;
				break;
			}
			swap(s[i], s[p]);
		}
		if(!f) {
			cout << "---\n";
		}
	}
	return 0;
}
