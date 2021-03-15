#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
    int K;
    cin >> K;
    string S, A, B;
    cin >> S >> A >> B;
    int N = S.size();
    vector<int> ans;
    vector<int> P(K, -1);
    vector<bool> mark(K);
    auto dfs = [&] (auto &&f, int i, bool high, bool low) -> bool {
      if (i == N || (low && high)) {
        for (int i = 0; i < K; ++i) {
          if (P[i] == -1) {
            for (int j = 0; j < K; ++j) {
              if (!mark[j]) {
                P[i] = j;
                mark[j] = true;
                break;
              }
            }
          }
        }
        ans = P;
        return true;
      }
      int C = S[i] - 'a';
      if (P[C] != -1) {
        if (P[C] < A[i] - 'a' && !high) {
          return false;
        }
        if (P[C] > A[i] - 'a') {
          high = true;
        }
        if (P[C] > B[i] - 'a' && !low) {
          return false;
        }
        if (P[C] < B[i] - 'a') {
          low = true;
        }
        return f(f, i + 1, high, low);
      } else {
        for (int j = 0; j < K; ++j) {
          if (!mark[j]) {
            P[C] = j;
            mark[j] = true;
            bool th = high;
            bool tl = low;
            if (P[C] < A[i] - 'a' && !high) {
              mark[j] = false;
              P[C] = -1;
              continue;
            }
            if (P[C] > A[i] - 'a') {
              th = true;
            }
            if (P[C] > B[i] - 'a' && !low) {
              mark[j] = false;
              P[C] = -1;
              continue;
            }
            if (P[C] < B[i] - 'a') {
              tl = true;
            }
            if (f(f, i + 1, th, tl)) {
              return true;
            }
            mark[j] = false;
            P[C] = -1;
          }
        }
      }
      return false;
    };
    if (!dfs(dfs, 0, false, false)) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 0; i < K; ++i) {
        cout << (char)(ans[i] + 'a');
      }
      cout << '\n';
    }
  }
  return 0;
}
