#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> p;
	p.resize(n);

	for(int &i : p) {
		cin >> i;
	}

	vector<int> pos;
	pos.resize(n);

	for(int i = 0; i < n; ++i) {
		pos[p[i] - 1] = i;
	}

	vector<int> v;

	for(int i = 0; i < k; ++i) {
		v.emplace_back(pos[n - i - 1]);
	}

	sort(v.begin(), v.end());

	long long ans1 = 0;

	for(int i = 0; i < k; ++i) {
		ans1 += n - i;
	}

	long long ans2 = 1;

	for(int i = 1; i < v.size(); ++i) {
		ans2 = ans2 * (v[i] - v[i - 1]) % P;
	}

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}
