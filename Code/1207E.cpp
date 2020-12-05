#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 14;

int main() {
	vector<int> fi;
	vector<int> se;

	for (int i = 1; i < N; ++i) {
		bool low = true;
		for (int j = 0; j < 7; ++j) {
			if (i >> j & 1) {
				low = false;
			}
		}	
		
		bool high = true;
		for (int j = 7; j < 14; ++j) {
			if (i >> j & 1) {
				high = false;
			}
		}

		if (low) {
			fi.emplace_back(i);
		}
		if (high) {
			se.emplace_back(i);
		}
	}

	while (fi.size() > 100) {
		fi.pop_back();
	}

	while (se.size() > 100) {
		se.pop_back();
	}

	cout << '?';
	for (int i : fi) {
		cout << ' ' << i;
	}
	cout << endl;

	int ans = 0;

	int x;
	cin >> x;

	for (int i = 0; i < 7; ++i) {
		if (x >> i & 1) {
			ans ^= 1 << i;
		}
	}	

	cout << '?';
	for (int i : se) {
		cout << ' ' << i;
	}
	cout << endl;

	int y;
	cin >> y;

	for (int i = 7; i < 14; ++i) {
		if (y >> i & 1) {
			ans ^= 1 << i;
		}
	}

	cout << '!' << ' ';
	cout << ans << endl;

	return 0;
}
