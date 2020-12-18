#include <bits/stdc++.h>

using namespace std;

const int p[] = { 2, 3, 5, 7 };

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> cnt(4);
	for (char c : s) {
		int x = c - '0';
		for (int i = 2; i <= x; ++i) {
			int t = i;
			for (int j = 0; j < 4; ++j) {
				while (t % p[j] == 0) {
					cnt[j] ++;
					t /= p[j];
				}
			}	
		}
	}

	vector<int> ans;
	for (int i = 0; i < cnt[3]; ++i) {
		ans.emplace_back(p[3]);
	}

	cnt[0] -= 4 * cnt[3];
	cnt[1] -= 2 * cnt[3];
	cnt[2] -= 1 * cnt[3];

	for (int i = 0; i < cnt[2]; ++i) {
		ans.emplace_back(p[2]);
	}

	cnt[0] -= 3 * cnt[2];
	cnt[1] -= 1 * cnt[2];

	for (int i = 0; i < cnt[1]; ++i) {
		ans.emplace_back(p[1]);
	}

	cnt[0] -= 1 * cnt[1];

	for (int i = 0; i < cnt[0]; ++i) {
		ans.emplace_back(p[0]);
	}

	sort(ans.begin(), ans.end(), greater<int> ());
	for (int i : ans) {
		cout << i;
	}
	cout << '\n';

	return 0;
}
