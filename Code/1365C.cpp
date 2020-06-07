#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
	}

	vector<int> cnt(n);
	vector<int> pos(n);
	
	for(int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}

	for(int i = 0; i < n; ++i) {
		int d = (pos[b[i]] - i + n) % n;
		cnt[d] += 1;
	}

	cout << *max_element(cnt.begin(), cnt.end()) << '\n';

	return 0;
}
