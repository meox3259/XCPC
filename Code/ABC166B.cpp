#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> cnt(n);

	for(int i = 0; i < k; ++i) {
		int d;
		cin >> d;
		for(int j = 0; j < d; ++j) {
			int x;
			cin >> x;
			++cnt[x - 1];
		}
	}
	
	int ans = 0;
	for(int i : cnt) {
		if(i == 0) {
			++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
