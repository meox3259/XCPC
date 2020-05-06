#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	sort(x.begin(), x.end());

	int last = -1;
	int ans1 = 0;

	for(int i : x) {
		if(last < i - 1) {
			++ans1;
			last = i + 1;
		}
	}

	last = -1;
	int ans2 = 0;

	for(int i : x) {
		if(last != i + 1) {
			++ans2;
			last = max(last + 1, i - 1);
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';

	return 0;
}
