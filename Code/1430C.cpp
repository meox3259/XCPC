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
		iota(a.begin(), a.end(), 1);

		cout << 2 << '\n';
		while(a.size() > 1) {
			int x = a.back(); a.pop_back();
			int y = a.back(); a.pop_back();
			cout << x << ' ' << y << '\n';
			a.emplace_back((x + y + 1) / 2);
		}
	}

	return 0;
}
