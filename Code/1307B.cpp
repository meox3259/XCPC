#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, x;
		cin >> n >> x;
		set<int> s;
		int far = 0;
		for(int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			s.emplace(a);
			far = max(far, a);
		}
		if(s.count(x) > 0) {
			cout << 1 << '\n';
		} else {
			cout << max(2, (x + far - 1) / far) << '\n';
		}
	}
	return 0;
}
