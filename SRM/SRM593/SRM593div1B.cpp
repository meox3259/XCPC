#include <bits/stdc++.h>

using namespace std;

class MayTheBestPetWin {
    public:
    int calc(vector <int> A, vector <int> B) {
        int n = A.size();
        int m = 0;
        for(int i : B) {
            m += i;
        }
        vector<vector<int> > dp(n + 1, vector<int> (m + 1));
        dp[0][0] = 1;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(j - A[i] >= 0) {
                    dp[i + 1][j - A[i]] |= dp[i][j];
                }
                dp[i + 1][j + B[i]] |= dp[i][j];
            }
            sum += B[i];
        }
        for(int i = 0; i <= m; ++i) {
            
        }
    }
};