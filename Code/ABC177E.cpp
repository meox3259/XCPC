#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> cnt(N + 1);
	for(int i : a) {
		cnt[i] += 1;
	}

	bool ok = true;
	for(int i = 2; i <= N; ++i) {
		int tot = 0;
		for(int j = i; j <= N; j += i) {
			tot += cnt[j];
		}
		if(tot > 1) {
			ok = false;
		}
	}

	if(ok) {
		cout << "pairwise coprime" << '\n';
	} else {
		int g = 0;
		for(int i : a) {
			g = __gcd(i, g);
		}
		if(g == 1) {
			cout << "setwise coprime" << '\n';
		} else {
			cout << "not coprime" << '\n';
		}
	}

	return 0;
}
