#include <bits/stdc++.h>

using namespace std;

const long long N = 1LL << 32;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l;
	cin >> l;

	long long t = 1;
	bool ok = false;
	bool big = false;

	vector<pair<int, int> > st;
	vector<long long> mul;

	auto trans = [&] (string s) {
		int ret = 0;
		for (char c : s) {
			ret = ret * 10 + c - '0';
		}
		return ret;
	};	

	long long ans = 0;

	for (int _ = 0; _ < l; ++_) {
		string c;
		cin >> c;

		string v;
		if (c == "for") {
			cin >> v;
		}

		ok |= (ans >= N);

		if (ok) {
			continue;
		}

		if (c == "for") {
			int x = trans(v);
			if (st.empty()) {
				st.emplace_back(x, 0);
				mul.emplace_back(x);
			} else {
				st.emplace_back(x, (st.back().second | (mul.back() * x >= N)));
				mul.emplace_back(mul.back() * x);
			}
		}

		if (c == "end") {
			mul.pop_back();
			st.pop_back();
		}

		if (c == "add") {
			if (st.empty()) {
				ans += 1;				
			} else {
				if (st.back().second) {
					ok = true;
				} else {
					ans += mul.back();
				}
			}
		}
	}

	ok |= (ans >= N);

	if (ok) {
		cout << "OVERFLOW!!!" << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
