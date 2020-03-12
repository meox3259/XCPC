#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		vector<int> a;
		a.resize(3);
		for(int i = 0; i < 3; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		int ans = 0;
		for(int i = 0; i < 3; ++i) {
			if(a[i] > 0) {
				--a[i];
				++ans;
			}
		}
		for(int i = 0; i < 3; ++i) {
			for(int j = i + 1; j < 3; ++j) {
				if(a[i] > 0 && a[j] > 0) {
					--a[i];
					--a[j];
					++ans;
				}
			}
		}
		if(a[0] * a[1] * a[2] > 0) {
			++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}
