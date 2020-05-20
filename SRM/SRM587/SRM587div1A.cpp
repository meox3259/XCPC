#include <bits/stdc++.h>

using namespace std;

class JumpFurther {
	public:
	int furthest(int N, int badStep) {
		int sum = 0;
		int ans = N * (N + 1) / 2;
		for(int i = 1; i <= N; ++i) {
			sum += i;
			if(sum == badStep) {
				ans -= 1;
				break;
			}
		}
		return ans;
	}
};
