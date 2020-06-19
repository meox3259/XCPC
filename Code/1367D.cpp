#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while(q--) {
		string s;
		cin >> s;
		
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int cur = 26;

		vector<int> cnt(26);
		for(char c : s) {
			cnt[c - 'a'] += 1;
		}

		string ans(n, ' ');

		while(1) {
			int c = 0;
			for(int i = 0; i < n; ++i) {
				if(a[i] == 0) {
					c += 1;
				}
			}
			if(c == 0) {
				break;
			}
			cur -= 1;
			while(cnt[cur] < c) {
				cur -= 1;
			}
			vector<int> tmp = a;
			for(int i = 0; i < n; ++i) {
				if(tmp[i] == 0) {
					a[i] = -1;
					ans[i] = (char)(cur + 'a');
					for(int j = 0; j < n; ++j) {
						if(a[j] > 0) {
							a[j] -= abs(i - j);
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
