#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> ans;
  auto dfs = [&] (auto &&f, int X, int Y, int S) -> void {
    if (__builtin_popcount(S ^ ((1 << N) - 1)) == 1) {
      ans.push_back(X);
      ans.push_back(Y);
      return;
    }
    for (int i = 0; i < N; ++i) {
      if ((X >> i & 1) ^ (Y >> i & 1)) {
        S ^= 1 << i;
        int mid = X;
        for (int j = 0; j < N; ++j) {
          if (!(S >> j & 1)) {
            mid ^= 1 << j; 
            break;
          }
        }
        f(f, X, mid, S);
        f(f, mid ^ (1 << i), Y, S);
        break;
      }
    }
  };
  if (__builtin_popcount(A ^ B) & 1) {
    cout << "YES" << '\n';
    dfs(dfs, A, B, 0);
    for (int i = 0; i < (1 << N); ++i) {
      cout << ans[i] << " \n"[i == (1 << N) - 1];
    }
  } else {
    cout << "NO" << '\n';
  }

  return 0;
}
