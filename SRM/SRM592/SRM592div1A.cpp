#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndBalls {
	public:
	int getNumber(string S) {
		int ans = 0;
		int r = 0;
		int g = 0;
		int b = 0;

		for(char c : S) {
			ans += r + g + b;
			if(c == 'R') {
				r = min(r + 1, 2);
			}
			if(c == 'G') {
				g = min(g + 1, 2);
			}
			if(c == 'B') {
				b = min(b + 1, 2);
			}
		}

		return ans;
	}
};
