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

		set<int> s;
		for(int i : a) {
			s.emplace(i);
		}

		if(s.size() == 1) {
			cout << a.size() << '\n';
		} else {
			cout << 1 << '\n';
		}
	}

	return 0;
}
