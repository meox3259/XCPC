#include <bits/stdc++.h>

using namespace std;

int main() {
	auto query = [&] (long long x) {
		if (x == 0) {
			return 1;
		}
		cout << '?' << ' ' << x << endl;
		char ret;
		cin >> ret;
		if (ret == 'Y') {
			return 1;
		} else {
			return -1;
		}
	};

	long long cur = 9999999999;
	bool ok = false;
	for (int b = 10; b >= 1; --b) {
		int sgn = query(cur / 10);
		if (b == 1) {
			int o = query(10);	
			if (o == 1) {
				long long val = 10;
				for (int i = 0; i < 11; ++i) {
					if (query(val) == -1) {
						cout << '!' << ' ' << val - 1 << endl;
						exit(0);
					}
					val = val * 10;
				}
			}
		}
		if (b == 1 || sgn == -1) {
			ok = true;
			long long val = 0;
			for (int i = 0; i < b - 1; ++i) {
				int l = 0;
				int r = 10;
				while (r - l > 1) {
					int mid = l + r >> 1;
					if (query(val * 10 + mid) == 1) {
						l = mid;
					} else {
						r = mid;
					}
				}
				val = val * 10 + l;
			}
			for (int i = (b == 1 ? 1 : 0); i < 10; ++i) {
				if (query(val * 100 + i * 10 + 9) == 1) {
					cout << '!' << ' ' << val * 10 + i << endl;
					exit(0);
				}	
			}
			exit(0);
		} else {
			cur = cur / 10;
		}
	}

	cerr << "here" << '\n';

	return 0;
}
