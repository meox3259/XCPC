#include <bits/stdc++.h>

using namespace std;

template <typename T>
void chkmax(T &x, T y) {
	if(x < y) {
		x = y;
	}
}

class KeyDungeonDiv1 {
	public:
	int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) {
		int n = doorR.size();
		vector<vector<int> > dp(1 << n, vector<int> (135, -1));

		dp[0][keys[0]] = keys[2];

		for(int S = 0; S < 1 << n; ++S) {
			int dR = 0;
			int dG = 0;
			int dW = 0;
			for(int i = 0; i < n; ++i) {
				if(S >> i & 1) {
					dR -= doorR[i];
					dR += roomR[i];
					dG -= doorG[i];
					dG += roomG[i];
					dW += roomW[i];
				}
			}
			for(int curR = 0; curR < 135; ++curR) {
				if(dp[S][curR] >= 0) {
					for(int i = 0; i < n; ++i) {
						if(!(S >> i & 1)) {
							int delta = curR - keys[0] - dR;
							if(delta >= 0) {
								int GW = keys[2] + dW - delta - dp[S][curR];
								if(GW >= 0) {
									int curG = keys[1] + dG + GW;
									int curW = dp[S][curR];
									int need = max(0, doorR[i] - curR) + max(0, doorG[i] - curG);
									if(need <= curW) {
										chkmax(dp[S ^ (1 << i)][max(0, curR - doorR[i]) + roomR[i]], dp[S][curR] - need + roomW[i]);
									}
								}
							}
						}
					}
				}
			}
		}

		int ans = 0;

		for(int S = 0; S < 1 << n; ++S) {
			int sR = keys[0];
			int sG = keys[1];
			int sW = keys[2];
			for(int i = 0; i < n; ++i) {
				if(S >> i & 1) {
					sR += roomR[i] - doorR[i];
					sG += roomG[i] - doorG[i];
					sW += roomW[i];
				}
			}
			for(int R = 0; R < 135; ++R) {
				if(dp[S][R] >= 0) {
					chkmax(ans, sR + sG + sW);
				}
			}
		}

		return ans;
	}	
};
