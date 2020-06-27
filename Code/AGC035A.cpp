#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int x = a[0];
	int y = a[n - 1];

	multiset<int> s;
	for(int i = 1; i < n - 1; ++i) {
		s.emplace(a[i]);
	}

	vector<int> b(n);
	b[0] = x;
	b[1] = y;
	for(int i = 2; i < n; ++i) {
		b[i] = x ^ y;
		if(s.find(b[i]) == s.end()) {
			cout << "No" << '\n';
			exit(0);
		}
		x = y;
		y = b[i];
		s.erase(s.find(b[i]));
	}

	for(int i = 0; i < n; ++i) {
		if((b[i] ^ b[(i + 1) % n]) != b[(i + 2) % n]) {
			cout << "No" << '\n';
			exit(0);
		}
	}

	cout << "Yes" << '\n';

	return 0;
}
