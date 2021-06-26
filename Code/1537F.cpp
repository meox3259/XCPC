#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N, M;
    cin >> N >> M;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
      cin >> v[i];
    }
    vector<long long> t(N);
    for (int i = 0; i < N; ++i) {
      cin >> t[i];
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      adj[X].push_back(Y);
      adj[Y].push_back(X);
    }
    vector<int> col(N, -1);
    auto dfs = [&] (auto &&f, int X, int C) -> bool {
      col[X] = C; 
      for (int Y : adj[X]) {
        if (col[Y] == -1) {
          if (!f(f, Y, C ^ 1)) {
            return false;
          }
        } else if (col[X] == col[Y]) {
          return false;
        }
      }
      return true;
    };
    if (!dfs(dfs, 0, 0)) {
      if (abs(accumulate(v.begin(), v.end(), 0LL)) % 2 == abs(accumulate(t.begin(), t.end(), 0LL)) % 2) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      vector<long long> dv(2);
      vector<long long> dt(2);
      for (int i = 0; i < N; ++i) {
        dv[col[i]] += v[i];
        dt[col[i]] += t[i];
      } 
      if (dv[0] - dt[0] == dv[1] - dt[1]) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
}
