#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  int N;
  cin >> N;
  vector<long long> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  vector<int> P(N);
  for (int i = 1; i < N; ++i) {
    cin >> P[i];
    P[i] --;
  }
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    adj[P[i]].push_back(i);
  }
  vector<vector<long long>> dp(N + 1, vector<long long> (N + 1));
  vector<int> sz(N);
  auto dfs = [&] (auto &&f, int X) -> void {
    sz[X] = 1;
    dp[X][0] = 1;
    vector<long long> tmp(N + 1);
    for (int Y : adj[X]) {
      f(f, Y);
      vector<long long> tmp(N + 1);
      for (int i = 0; i <= sz[X]; ++i) {
        for (int j = 0; j <= sz[Y]; ++j) {
          tmp[i + j] += dp[X][i] * dp[Y][j];
          tmp[i + j] %= MOD;
        }
      }
      swap(tmp, dp[X]);
      sz[X] += sz[Y];
    }
    for (int i = sz[X] - 1; i >= 0; --i) {
      dp[X][i + 1] += dp[X][i] * (sz[X] - 1 - i);
      dp[X][i + 1] %= MOD;
    }
  };
  dfs(dfs, 0);
  long long Ans = 0;
  for (int i = 0; i <= N; ++i) {
    if (i % 2 == 0) {
      Ans += dp[0][i] * fac[N - i];
      Ans %= MOD;
    } else {
      Ans -= dp[0][i] * fac[N - i];
      Ans %= MOD;
      Ans += MOD;
      Ans %= MOD;
    }
  }
  cout << Ans << '\n';
}
