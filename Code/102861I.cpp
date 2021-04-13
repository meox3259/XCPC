#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int P;
    cin >> P;
    P --;
    adj[P].push_back(i);
  }
  vector<vector<long long>> dp(N, vector<long long> (2));
  auto dfs = [&] (auto &&f, int X) -> void {
    if (adj[X].empty()) {
      dp[X][1] = 1;
      return;
    }
    int M = adj[X].size();
    vector<long long> pre(M + 2);
    vector<long long> suf(M + 2);
    vector<long long> zero;
    vector<long long> one;
    for (int Y : adj[X]) {
      f(f, Y);
      zero.push_back(dp[Y][0]);
      one.push_back(dp[Y][1]);
    }
    pre[0] = 1;
    for (int i = 0; i < M; ++i) {
      pre[i + 1] = pre[i] * (zero[i] + one[i]) % P;
    }
    suf[M + 1] = 1;
    for (int i = M; i >= 1; --i) {
      suf[i] = suf[i + 1] * (zero[i - 1] + one[i - 1]) % P;
    }
    dp[X][0] = pre[M];
    for (int i = 0; i < M; ++i) {
       dp[X][1] += pre[i] * suf[i + 2] % P * one[i] % P;
       dp[X][1] %= P;
    }
  };
  dfs(dfs, 0);
  cout << (dp[0][0] + dp[0][1]) % P << '\n';
}
