#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	
	vector<string> c(h);
	for(int i = 0; i < h; ++i) {
		cin >> c[i];
	}

	int ans = 0;
	for(int x = 0; x < 1 << h; ++x) {
		for(int y = 0; y < 1 << w; ++y) {
			int cnt = 0;
			for(int i = 0; i < h; ++i) {
				for(int j = 0; j < w; ++j) {
					if(c[i][j] == '#' && !(x >> i & 1) && !(y >> j & 1)) {
						cnt += 1;
					}
				}
			}
			if(cnt == k) {
				ans += 1;
			}
		}
	} 

	cout << ans << '\n';

	return 0;
}
