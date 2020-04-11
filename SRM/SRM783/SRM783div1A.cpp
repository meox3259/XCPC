#include <bits/stdc++.h>

using namespace std;

class CardboardBoxes {
	public:
	long long count(long long S) {
		if(S % 2 != 0) {
			return 0;
		}

		S /= 2;

		long long ret = 0;

		for(long long i = 1; i * i <= S; ++i) {
			if(S % i == 0) {
				long long a = i;
				long long b = S / i;

				if(a != b) {
					long long t = min(a, b) - 1;
					ret += min(a / 2, t);
					ret += min(b / 2, t);
				} else {
					long long t = min(a, b) - 1;
					ret += min(a / 2, t);
				}
			}
		}

		return ret;
	}
};

