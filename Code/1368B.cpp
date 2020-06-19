#include <bits/stdc++.h>

using namespace std;

int main() {
	long long k;
	cin >> k;
	
	long long cur = 1;

	int p = 0;

	vector<int> cnt(10, 1);
	string s = "codeforces";

	while(cur < k) {
		cur = cur / cnt[p] * (cnt[p] + 1);
		cnt[p] += 1;
		p = (p + 1) % 10;
	}

	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			cout << s[i];
		}
	}

	cout << '\n';

	return 0;
}
