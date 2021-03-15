#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 21;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> cnt(M);
  vector<int> vis(M, -1);
  int ans = 0;
  for (int i = N - 1; i >= 0; --i) {
    queue<int> Q; 
    Q.push(A[i]);
    vis[A[i]] = i;
    while (!Q.empty()) {
      int X = Q.front();
      Q.pop();
      if (cnt[X] >= 2) {
        continue;
      }
      cnt[X] ++;
      for (int j = 0; j < 21; ++j) {
        if (X >> j & 1) {
          int Y = X ^ (1 << j);
          if (vis[Y] != i) {
            vis[Y] = i;
            Q.push(Y);
          }
        }
      }
    }
    if (i <= N - 3) {
      int S = 0;
      for (int j = 20; j >= 0; --j) {
        if (!(A[i] >> j & 1)) {
          int S0 = S ^ (1 << j);
          if (cnt[S0] >= 2) {
             S ^= 1 << j;
          }
        }
      }
      ans = max(ans, A[i] | S);
    }
  }
  cout << ans << '\n';
  return 0;
}
