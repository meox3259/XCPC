#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long T;
	cin >> n >> T;

	string s;
	cin >> s;

	T -= 1 << (s.back() - 'a');
	s.pop_back();

	T += 1 << (s.back() - 'a');
	s.pop_back();

	vector<int> cnt(26);
	for (int i = 0; i < n - 2; ++i) {
		cnt[s[i] - 'a'] ++;
	}

	for (int i = 25; i >= 0; --i) {
		for (int j = 0; j < cnt[i]; ++j) {
			if (T > 0) {
				T -= 1 << i;
			} else {
				T += 1 << i;
			}
		}
	}

	if (T == 0) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
