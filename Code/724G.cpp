#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<long long>> C(64, vector<long long> (64));
  C[0][0] = 1;
  for (int i = 1; i < 64; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
  }
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, long long>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    long long W;
    cin >> X >> Y >> W;
    X --;
    Y --;
    adj[X].emplace_back(Y, W);
    adj[Y].emplace_back(X, W);
  }
  vector<bool> vis(N);
  vector<long long> d(N);
  long long Ans = 0;
  for (int i = 0; i < N; ++i) {
    if (!vis[i]) {
      vector<long long> base;
      vector<long long> dis;
      auto dfs = [&] (auto &&f, int X, int Par) -> void {
        vis[X] = true;
        dis.push_back(d[X]);
        for (auto [Y, W] : adj[X]) {
          if (!vis[Y]) {
            d[Y] = d[X] ^ W;
            f(f, Y, X);
          } else if (Y != Par && X < Y) {
            base.push_back(d[X] ^ d[Y] ^ W);
          }
        }
      };
      dfs(dfs, i, -1);
      if (dis.size() == 1) {
        continue;
      }
      vector<long long> B(63);
      for (auto V : base) {
        for (int j = 0; j < 63; ++j) {
          if (V >> j & 1) {
            if (!B[j]) {
              B[j] = V;
              break;
            } else {
              V ^= B[j];
            }
          }
        }  
      }
      for (int j = 0; j < 63; ++j) {
        vector<long long> cnt(2);
        for (long long D : dis) {
          if (D >> j & 1LL) {
            cnt[1] ++; 
          } else {
            cnt[0] ++;
          }
        }
        vector<long long> bit(2);
        for (int k = 0; k < 63; ++k) {
          if (B[k] != 0) {
            if (B[k] >> j & 1LL) {
              bit[1] ++;
            } else {
              bit[0] ++;
            }
          }
        }
        long long tot = 0;
        for (int i = 1; i < 63; i += 2) {
          tot += C[bit[1]][i];
          tot %= P;
        }
        Ans += (1LL * cnt[0] * (cnt[0] - 1) / 2 + 1LL * cnt[1] * (cnt[1] - 1) / 2) % P * tot % P * ((1LL << j) % P) % P * ((1LL << bit[0]) % P) % P;
        Ans %= P;
        tot = 0;
        for (int i = 0; i < 63; i += 2) {
          tot += C[bit[1]][i];
          tot %= P;
        }
        Ans += 1LL * cnt[0] * cnt[1] % P * tot % P * ((1LL << j) % P) % P * ((1LL << bit[0]) % P) % P;
        Ans %= P;
      } 
    }
  }
  cout << Ans << '\n';
}
