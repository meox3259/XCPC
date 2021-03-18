#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      A[i] %= M;
    }
    vector<int> cnt(M);
    for (int i = 0; i < N; ++i) {
      cnt[A[i]] ++;
    }
    int Ans = 0;
    Ans += (cnt[0] != 0);
    vector<pair<int, int>> P;
    for (int i = 1; i < M; ++i) {
      int j = M - i;
      if (j >= i) {
        P.emplace_back(i, j);
      }
    }
    for (auto [X, Y] : P) {
      if (X == Y) {
        if (cnt[X] > 0) {
          Ans ++;
        }
      } else {
        int A = cnt[X];
        int B = cnt[Y];
        if (A <= 0 && B <= 0) {
          continue;
        }
        if (A > B) {
          swap(A, B);
        }
        if (abs(A - B) <= 1) {
          Ans ++;
        } else {
          Ans ++;
          Ans += B - A - 1;
        }
      }
    }
    cout << Ans << '\n';
  }
  return 0;
}
