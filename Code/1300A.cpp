#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a;
		a.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int sum = 0, cnt = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] == 0) {
				++a[i];
				++cnt;
			}
			sum += a[i];
		}
		if(sum == 0) {
			++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}
