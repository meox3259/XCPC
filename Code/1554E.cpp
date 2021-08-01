#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      adj[X].push_back(Y);
      adj[Y].push_back(X);
    }
    vector<int> Ans(N + 1);
    Ans[1] = 1;
    for (int i = 0; i < N - 1; ++i) {
      Ans[1] *= 2;
      Ans[1] %= P;
    }
    for (int K = 2; K < N; ++K) {
      if ((N - 1) % K == 0) {
        vector<int> d(N);
        bool ok = true;
        auto dfs = [&] (auto &&f, int X, int F) -> void {
          for (int Y : adj[X]) {
            if (Y != F) {
              f(f, Y, X);
            }
          }
          if (d[X] % K == 0) {
            if (F != -1) {
              d[F] ++;
            }
          } else if (d[X] % K == K - 1) {
            d[X] ++;
          } else {
            ok = false;
          }
        };
        dfs(dfs, 0, -1);
        if (ok) {
          Ans[K] = 1;
        }
      }
    }           
    for (int i = N; i >= 1; --i) {
      for (int j = i + i; j <= N; j += i) {
        Ans[i] -= Ans[j];
        Ans[i] += P;
        Ans[i] %= P;
      }
    }
    for (int i = 1; i <= N; ++i) {
      cout << Ans[i] << " \n"[i == N];
    }
  }
}
