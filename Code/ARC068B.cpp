#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<int> s;

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		
		s.emplace(x);
	}

	int ans = s.size() - (s.size() + 1 & 1);

	cout << ans << '\n';

	return 0;

}
