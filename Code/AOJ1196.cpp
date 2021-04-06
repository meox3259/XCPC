#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  while (cin >> N) {
    if (N == 0) {
      break;
    }
    vector<int> P(N);
    for (int i = 1; i < N; ++i) {
      cin >> P[i];
      P[i] --;
    }
    vector<int> D(N);
    for (int i = 1; i < N; ++i) {
      cin >> D[i];
    }
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 1; i < N; ++i) {
      adj[P[i]].emplace_back(i, D[i]);
      adj[i].emplace_back(P[i], D[i]);
    }
    vector<bool> leaf(N);
    for (int i = 0; i < N; ++i) {
      if (adj[i].size() == 1) {
        leaf[i] = true;
      }
    }
    int Weight = accumulate(D.begin(), D.end(), 0);
    int S = -1;
    for (int i = 0; i < N; ++i) {
      if (!leaf[i]) {
        S = i;
        break;
      }
    }
    vector<int> dp(N);
    int chain = 0;
    auto dfs = [&] (auto &&f, int X, int Par) -> void {
      int Max = 0;
      for (auto [Y, W] : adj[X]) {
        if (Y != Par && !leaf[Y]) {
          f(f, Y, X);  
          chain = max(chain, dp[X] + dp[Y] + W);
          dp[X] = max(dp[X], dp[Y] + W);
        } 
      }
    };
    dfs(dfs, S, -1);
    for (int i = 0; i < N; ++i) {
      for (auto [j, W] : adj[i]) {
        if (!leaf[i] && !leaf[j]) {
          Weight += W;
        }
      }
    }
    cout << Weight - chain << '\n';
  }
}
