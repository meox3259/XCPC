#include <bits/stdc++.h>

using namespace std;

class ABBAReplace {
	public:
	int countSteps(string Sprefix, int N, int seed, int threshold) {
		long long state = seed;
		string s = Sprefix;

		while(s.size() < N) {
			state = (state * 1103515245 + 12345) % (1LL << 31);
			if(state < threshold) {
				s += 'A';
			} else {
				s += 'B';
			}
		}

		int ca = 0;
		int cb = 0;
		int ret = 0;

		reverse(s.begin(), s.end());

		while(!s.empty() && s.back() == 'B') {
			s.pop_back();
		}

		reverse(s.begin(), s.end());

		for(char c : s) {
			if(c == 'A') {
				++ca;
				cb = max(0, cb - 1);
			} else {
				ret = max(ret, ca + cb);
				++cb;
			}
		}

		return ret;
	}
};
