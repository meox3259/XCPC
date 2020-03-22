#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, k;
	cin >> h >> w >> k;
	
	vector<string> s;
	s.resize(h);

	for(int i = 0; i < h; ++i) {
		cin >> s[i];
	}

	int ans = h * w;

	for(int S = 0; S < 1 << (h - 1); ++S) {
		vector<int> sum;
		sum.resize(h);

		bool ok = true;

		int cnt = __builtin_popcount(S);

		for(int j = 0; j < w; ++j) {
			int p = 0;

			vector<int> tmp;
			tmp.resize(h);

			for(int i = 0; i < h; ++i) {
				tmp[p] += (s[i][j] == '1');

				if(S >> i & 1) {
					++p;
				}
			}		

			if(*max_element(tmp.begin(), tmp.end()) > k) {
				ok = false;
				break;
			}

			bool cut = false;

			for(int i = 0; i <= p; ++i) {
				if(sum[i] + tmp[i] > k) {
					cut = true;
					break;
				}
			}

			if(cut) {
				++cnt;

				for(int i = 0; i <= p; ++i) {
					sum[i] = tmp[i];
				}
			} else {
				for(int i = 0; i <= p; ++i) {
					sum[i] += tmp[i];
				}
			}
		}

		if(ok) {
			ans = min(ans, cnt);
		}
	}

	cout << ans << '\n';

	return 0;
}
