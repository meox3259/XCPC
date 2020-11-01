#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();
	
	if(n == 1) {
		int x = s[0] - '0';
		if(x % 8 == 0) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
		exit(0);
	}

	if(n == 2) {
		int x = s[0] - '0' + (s[1] - '0') * 10;
		int y = s[1] - '0' + (s[0] - '0') * 10;
		if(x % 8 == 0 || y % 8 == 0) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
		exit(0);
	}

	vector<int> cnt(10);
	for(char c : s) {
		cnt[c - '0'] += 1;
	}

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			for(int k = 0; k < 10; ++k) {
				if((i * 100 + j * 10 + k) % 8 == 0) {
					cnt[i] -= 1;
					cnt[j] -= 1;
					cnt[k] -= 1;
					if(*min_element(cnt.begin(), cnt.end()) >= 0) {
						cout << "Yes" << '\n';
						exit(0);
					}
					cnt[i] += 1;
					cnt[j] += 1;
					cnt[k] += 1;
				}
			}
		}
	}

	cout << "No" << '\n';

	return 0;
}
