#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

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

        for (int i = 0; i < n - 1; ++i) {
            a[0] += min(0, a[i + 1] - a[i]);
        }

        if (a[0] >= 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
	}

	return 0;
}
