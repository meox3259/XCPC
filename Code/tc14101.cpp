#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class DoubleOrOneEasy {
	public:
		int minimalSteps(int a, int b, int A, int B) {
			const int inf = 2e9;
			ll ans = inf;
			for(int i = 0; i < 32; ++i) {
				ll dif_a = A - ((ll)a << i);
				ll dif_b = B - ((ll)b << i);
				if(dif_a != dif_b || dif_a < 0) {
					continue;
				}
				ans = min(ans, i + (dif_a >> i) + (__builtin_popcount(dif_a & ((1 << i) - 1))));
			}
			return ans == inf ? -1 : ans;
		}
};

