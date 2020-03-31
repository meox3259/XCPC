#include <bits/stdc++.h>

using namespace std;

class BigFatInteger {
	public:
	int minOperations(int A, int B) {
		map<int, int> cnt;

		for(int i = 2; i * i <= A; ++i) {
			if(A % i == 0) {
				while(A % i == 0) {
					++cnt[i];
					A /= i;
				}
			}
		}

		if(A > 1) {
			++cnt[A];
		}

		for(auto& p : cnt) {
			p.second *= B;
		}

		int mx = 0;

		for(auto& p : cnt) {
			mx = max(mx, p.second);
		}

		int ans = cnt.size();

		for(int i = 30; i >= 0; --i) {
			if(mx >> i & 1) {
				ans += i;

				if((1 << i) != mx) {
					++ans;
				}

				break;
			}
		}

		return ans;
	}
};
