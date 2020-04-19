#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> ans;
	ans.resize(n);

	for(int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		++ans[x - 1];
	}

	for(int i : ans) {
		cout << i << '\n';
	}

	return 0;
}
