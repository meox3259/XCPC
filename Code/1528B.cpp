#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  int N;
  cin >> N;
  set<vector<pair<int, int>>> S;
  vector<bool> vis(N + N);
  auto dfs = [&] (auto &&f, vector<pair<int, int>> A) -> void {
    bool ok = true;
    for (int i = 0; i < N + N; ++i) {
      if (!vis[i]) {
        ok = false;
      }
    }
    if (ok) {
      bool ri = true;
      for (auto [L1, R1] : A) {
        for (auto [L2, R2] : A) {
          if ((R1 - L1 != R2 - L2) && !(L1 <= L2 && R2 <= R1) && !(L2 <= L1 && R1 <= R2)) {
            ri = false;
          }
        }
      }
      if (!ri) {
        return;
      }
      sort(A.begin(), A.end());
      S.insert(A);
      return;
    }
    for (int i = 0; i < N + N; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        for (int j = i + 1; j < N + N; ++j) {
          if (!vis[j]) {
            vis[j] = true;
            A.emplace_back(i, j);
            f(f, A);
            A.pop_back();
            vis[j] = false;
          }
        }
        vis[i] = false;
      }
    }
  }; 
  vector<pair<int, int>> tmp;
  dfs(dfs, tmp);
  for (auto vec : S) {
    puts("----------------------------");
    for (auto [L, R] : vec) {
      cout << L + 1 << ' ' << R + 1 << endl;
    }
  }
  cout << S.size() << '\n';
}
