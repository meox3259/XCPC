#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> ans;
		for(int d = 1; d <= y - x; ++d) {
			if((y - x) % d == 0) {
				for(int s = 1; s <= x; ++s) {
					vector<int> tmp;
					int cur = s;
					for(int i = 0; i < n; ++i) {
						tmp.emplace_back(cur);	
						cur += d;
					}
					bool okx = false;
					bool oky = false;
					for(int i = 0; i < n; ++i) {
						if(tmp[i] == x) {
							okx = true;
						}
						if(tmp[i] == y) {
							oky = true;
						}
					}
					if(okx && oky) {
						if(ans.empty() || *max_element(tmp.begin(), tmp.end()) < *max_element(ans.begin(), ans.end())) {
							swap(ans, tmp);
						}
					}
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}
