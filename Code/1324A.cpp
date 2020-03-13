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

		vector<int> cnt;
		cnt.resize(2);

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
	
			++cnt[x % 2];
		}
	
		if(cnt[0] > 0 && cnt[1] > 0) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}

	}
	return 0;
}
