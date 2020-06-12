#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int m = 10000001;

	vector<int> low(m);
	vector<int> p;
	vector<bool> mark(m);

	low[1] = 1;
	for(int i = 2; i < m; ++i) {
		if(!mark[i]) {
			p.emplace_back(i);
			low[i] = i;
		}
		for(int j = 0; j < p.size() && i * p[j] < m; ++j) {
			mark[i * p[j]] = true;
			low[i * p[j]] = p[j];
			if(i % p[j] == 0) {
				break;
			}
		}
	}

	vector<int> d1(n, -1);
	vector<int> d2(n, -1);

	for(int i = 0; i < n; ++i) {
		int v = a[i];
		while(v % low[a[i]] == 0) {
			v /= low[a[i]];
		}
		if(v != 1) {
			d1[i] = v;
			d2[i] = low[a[i]];
		}
	}

	for(int i : d1) {
		cout << i << ' ';
	}
	cout << '\n';

	for(int i : d2) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
