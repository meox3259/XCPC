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

		vector<int> p;
		p.resize(n);

		for(int &i : p) {
			cin >> i;
		}

		bool ok = true;

		for(int i = 0; i + 1 < n; ++i) {
			if(p[i + 1] - p[i] >= 2) {
				ok = false;
				break;
			}
		}

		if(ok) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
