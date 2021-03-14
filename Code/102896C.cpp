#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> P(N, -1);
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    cin >> P[i];
    P[i] --;
    adj[P[i]].push_back(i);
  }
  vector<vector<int>> opr(N);
  auto dfs = [&] (auto &&f, int x) -> void {
    for (int y : adj[x]) {
      f(f, y);
    }
    for (int y : adj[x]) {
      vector<int> tmp;
      int o = 0;
      auto add = [&] () -> void {
        if (o) {
          for (auto it = opr[x].rbegin(); it != opr[x].rend(); it = next(it)) {
            tmp.push_back(*it);
          }
        } else {
          for (auto it = opr[x].begin(); it != opr[x].end(); it = next(it)) {
            tmp.push_back(*it);
          }
        }
        o ^= 1;
      };
      add();
      tmp.push_back(y);
      for (int i : opr[y]) {
        add();
        tmp.push_back(i);
      }
      add();
      swap(opr[x], tmp);
    }
  };
  dfs(dfs, 0);
  cout << opr[0].size() << '\n';
  for (int i = 0; i < opr[0].size(); ++i) {
    cout << opr[0][i] + 1 << " \n"[i + 1 == opr[0].size()];
  }
  return 0;
}
