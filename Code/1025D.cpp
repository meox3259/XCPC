#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
int dp[2][705][705];
int g[705][705];
int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      g[i][j] = __gcd(A[i], A[j]);
    }
  }
  for (int i = 0; i < N; ++i) {
    if (g[i + 1][i] >= 2) {
      dp[1][i][i] = 1;
    }
    if (i >= 1 && g[i - 1][i] >= 2) {
      dp[0][i][i] = 1; 
    }
  }
  for (int L = 2; L <= N; ++L) {
    for (int i = 0; i + L - 1 < N; ++i) {
      int j = i + L - 1;
      for (int l = 0; l < 2; ++l) {
        for (int k = i; k <= j; ++k) {
          if (g[k][(l == 0 ? i - 1 : j + 1)] >= 2) {
            dp[l][i][j] |= ((k > i ? dp[1][i][k - 1] : 1) & (k < j ? dp[0][k + 1][j] : 1));
            if (dp[l][i][j]) {
              break;
            }
          } 
        }
      }
    }
  }
  if (dp[1][0][N - 1]) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
