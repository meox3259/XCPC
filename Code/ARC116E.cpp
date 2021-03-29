#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  int L = 0;
  int R = N + 1;
  auto check = [&] (int D) -> bool {
    auto dfs = [&] (auto &&f, int X, int Par) -> pair<int, int> {
      int tot = 0;
      int L = Inf;
      int R = -Inf;
      bool ch = false;
      for (int Y : adj[X]) {
        if (Y != Par) {
          auto [C, dep] = f(f, Y, X); 
          tot += C;
          L = min(L, dep);
          R = max(R, dep + 1);
          ch = true;
        }
      } 
      if (X == 0) {
        tot += (-L < R);
        return { tot, R };
      } else if (!ch) {
        return { 0, 1 };
      } else if (R == D + 1) {
        tot ++;
        return { tot, -D };
      }
      if (-L >= R) {
        return { tot, L + 1 };
      } 
      return { tot, R };
    };
    auto [C, dep] = dfs(dfs, 0, -1);
    return C <= K;
  };
  while (R - L > 1) {
    int Mid = L + R >> 1;
    if (check(Mid)) {
      R = Mid;
    } else {
      L = Mid;
    }
  }
  cout << R << '\n';
}
