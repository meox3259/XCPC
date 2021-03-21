#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  int N = H * W;
  vector<vector<int>> vis(H, vector<int> (W));
  vector<pair<int, int>> st;
  set<vector<pair<int, int>>> S;
  int Ans = 0;
  auto dfs = [&] (auto &&f, int A, int B) -> void {
    if (A == 0 && B == 0) {
      Ans ++;
      return;
    }
    bool ok = false;
    for (int i = 0; i < H; ++i) {
      if (ok) {
        break;
      }
      for (int j = 0; j < W; ++j) {
        if (!vis[i][j]) {
          ok = true;
          vis[i][j] ^= 1;
          st.emplace_back(i * W + j, -1);
          auto tmp = st;
          sort(tmp.begin(), tmp.end());
          if (S.find(tmp) == S.end()) {
            S.insert(tmp);
            f(f, A, B - 1);
          }
          st.pop_back();
          vis[i][j] ^= 1;
          break;
        }
      }
    } 
    ok = false;
    for (int i = 0; i < H; ++i) {
      if (ok) {
        break;
      }
      for (int j = 0; j < W; ++j) {
        if (i > 0 && !vis[i][j] && !vis[i - 1][j]) {
          ok = true;
          vis[i][j] ^= 1;
          vis[i - 1][j] ^= 1;
          st.emplace_back(i * W + j, (i - 1) * W + j);
          auto tmp = st;
          sort(tmp.begin(), tmp.end());
          if (S.find(tmp) == S.end()) {
            S.insert(tmp);
            f(f, A - 1, B);
          }
          st.pop_back();
          vis[i][j] ^= 1;
          vis[i - 1][j] ^= 1;
          break;
        }
      }
    }
    ok = false;
    for (int i = 0; i < H; ++i) {
      if (ok) {
        break;
      }
      for (int j = 0; j < W; ++j) {
        if (j > 0 && !vis[i][j] && !vis[i][j - 1]) {
          ok = true;
          vis[i][j] ^= 1;
          vis[i][j - 1] ^= 1;
          st.emplace_back(i * W + j, i * W + j - 1);
          auto tmp = st;
          sort(tmp.begin(), tmp.end());
          if (S.find(tmp) == S.end()) {
            S.insert(tmp);
            f(f, A - 1, B);
          }
          st.pop_back();
          vis[i][j] ^= 1;
          vis[i][j - 1] ^= 1;
          break;
        }
      }
    }
  };
  dfs(dfs, A, B);
  cout << Ans << '\n';
}
