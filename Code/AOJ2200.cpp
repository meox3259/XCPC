#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  while (cin >> N >> M) {
    if (N == 0 && M == 0) {
      break;
    }
    vector<vector<long long>> dL(N, vector<long long> (N, Inf));
    vector<vector<long long>> dS(N, vector<long long> (N, Inf));
    for (int i = 0; i < N; ++i) {
      dL[i][i] = dS[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
      int X, Y;
      long long W;
      char L;
      cin >> X >> Y >> W >> L;
      X --;
      Y --;
      if (L == 'L') {
        dL[X][Y] = min(dL[X][Y], W);
        dL[Y][X] = min(dL[Y][X], W);
      } else {
        dS[X][Y] = min(dS[X][Y], W);
        dS[Y][X] = min(dS[Y][X], W);
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          dL[i][j] = min(dL[i][j], dL[i][k] + dL[k][j]);
          dS[i][j] = min(dS[i][j], dS[i][k] + dS[k][j]);
        }
      }
    }
    int R;
    cin >> R;
    vector<int> Z(R);
    for (int i = 0; i < R; ++i) {
      cin >> Z[i];
      Z[i] --;
    }
    vector<vector<long long>> dp(R + 1, vector<long long> (N, Inf));
    dp[1][Z[0]] = 0;
    for (int i = 1; i < R; ++i) {
      for (int j = 0; j < N; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dL[Z[i - 1]][Z[i]]);
        for (int k = 0; k < N; ++k) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + dL[Z[i - 1]][j] + dS[j][k] + dL[k][Z[i]]); 
        } 
      }
    }
    cout << *min_element(dp[R].begin(), dp[R].end()) << '\n';
  }
}
