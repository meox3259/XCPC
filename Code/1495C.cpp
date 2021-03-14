#include <bits/stdc++.h>
using namespace std;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    bool f = false;
    vector<string> ans = S;
    for (int j = 0; j < M; j += 3) {
      for (int i = 0; i < N; ++i) {
        ans[i][j] = 'X';
      }
    }
    if (M % 3 == 0) {
      for (int i = 0; i < N; ++i) {
        if (S[i][M - 1] == 'X') {
          ans[i][M - 2] = 'X';
        }
      }
    }
    for (int j = 0; j + 3 < M; j += 3) {
      for (int i = 0; i < N; ++i) {
        bool ok = true;
        if (i > 0 && (S[i - 1][j + 1] == 'X' || S[i - 1][j + 2] == 'X')) {
          ok = false;
        }  
        if (i < N - 1 && (S[i + 1][j + 1] == 'X' || S[i + 1][j + 2] == 'X')) {
          ok = false;
        }
        if (ok) {
          ans[i][j + 1] = 'X';
          ans[i][j + 2] = 'X';
          break;
        }
      } 
    }
    for (int i = 0; i < N; ++i) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}
