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
		vector<int> b(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		vector<pair<int, int> > sa;
		vector<pair<int, int> > sb;

		for(int i = 0; i * 2 < n; ++i) {
			sa.push_back(minmax(a[i], a[n - i - 1]));
			sb.push_back(minmax(b[i], b[n - i - 1]));
		}

		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());

		if(sa == sb) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}
