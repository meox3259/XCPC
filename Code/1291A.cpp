#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		bool ok = false;

		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if((s[i] - '0') % 2 == 1 && (s[j] - '0') % 2 == 1) {
					ok = true;
					
					cout << s[i] << s[j] << '\n';
					
					break;
				}
			}

			if(ok) {
				break;
			}
		}

		if(!ok) {
			cout << -1 << '\n';
		}
	}

	return 0;
}
