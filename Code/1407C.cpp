#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> p(n);

	auto query = [&] (int i, int j) {
		cout << '?' << ' ' << i + 1 << ' ' << j + 1 << '\n';
		fflush(stdout);
		int ret;
		cin >> ret;
		return ret;
	};

	int cur = 0;
	for(int i = 1; i < n; ++i) {
		int x = query(cur, i);
		int y = query(i, cur);
		if(x > y) {
			p[cur] = x;
			cur = i;
		} else {
			p[i] = y;
		}
	}

	int mx = *max_element(p.begin(), p.end());
	if(mx != n) {
		p[cur] = n;
	} else {
		for(int i = 0; i < n; ++i) {
			if(p[i] == n) {
				p[cur] = query(cur, i);
			}
		}
	}

	cout << '!' << ' ';
	for(int i = 0; i < n; ++i) {
		cout << p[i] << " \n"[i == n - 1];
	}
	fflush(stdout);

	return 0;
}
