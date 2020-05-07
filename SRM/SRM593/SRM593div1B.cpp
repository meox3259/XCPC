#include <bits/stdc++.h>

using namespace std;

class MayTheBestPetWin {
    public:
    int calc(vector <int> A, vector <int> B) {
        int n = A.size();
        int m = 0;
		for(int i : A) {
			m += i;
		}
        for(int i : B) {
            m += i;
        }
		vector<int> dp(m + 1);
		dp[0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = m; j >= A[i] + B[i]; --j) {
				dp[j] |= dp[j - A[i] - B[i]];
			}
		}
		int ans = m;
		int sa = 0;
		int sb = 0;
		for(int i : A) {
			sa += i;
		}
		for(int i : B) {
			sb += i;
		}
		for(int i = 0; i <= m; ++i) {
			if(dp[i]) {
				ans = min(ans, max(abs(i - sa), abs(i - sb)));
			}	
		}
		return ans;
    }
};
