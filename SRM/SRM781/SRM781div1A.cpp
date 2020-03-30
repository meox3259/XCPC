#include <bits/stdc++.h>

using namespace std;

class EpicPartition {
	public:
		string createPartition(int N) {
			if(N % 4 != 0) {
				return "";
			}

			int a = 0;
			int c = 0;

			string ans = "";

			int cur = 1;

			for(int i = 0; i < N; ++i) {
				ans += "abba";
				a += 2 * cur + 3;
				cur += 4;
			}

			for(int i = 0; i < N; ++i) {
				ans += "cc";
				c += 2 * cur + 1;
				cur += 2;
			}

			for(int x = 0; x < ans.size(); ++x) {
				if(ans[x] == 'c') {
					int y = x;
					while(a * 2 < c) {
						if(y == 0 || ans[y - 1] == 'c') {
							break;
						} 

						swap(ans[y], ans[y - 1]);
						swap(ans[y - 1], ans[y - 2]);

						a += 1;
						c -= 2;
						y -= 2;
					}
				}
			}

			return ans;
		}
};
