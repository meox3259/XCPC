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

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> cnt(102);
	for(int i : a) {
		cnt[i] += 1;
	}

	int x = 0;
	for(int i = 0; i < 102; ++i) {
		if(cnt[i] == 0) {
			x = i;
			break;
		}
		cnt[i] -= 1;
	}

	int y = 0;
	for(int i = 0; i < 102; ++i) {
		if(cnt[i] == 0) {
			y = i;
			break;
		}
		cnt[i] -= 1;
	}

	cout << x + y << '\n';
	}

	return 0;
}
