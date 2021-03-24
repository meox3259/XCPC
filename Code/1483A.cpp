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
    vector<int> K(M);
    vector<vector<int>> F(M);
    vector<int> Ans(M, -1);
    for (int i = 0; i < M; ++i) {
      cin >> K[i];
      F[i].resize(K[i]);
      for (int j = 0; j < K[i]; ++j) {
        cin >> F[i][j];
        F[i][j] --;
      }
    }
    vector<int> cnt(N);
    for (int i = 0; i < M; ++i) {
      cnt[F[i][0]] ++;
      Ans[i] = F[i][0];
    }
    int P = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    for (int i = 0; i < M; ++i) {
      if (cnt[P] <= (M + 1) / 2) {
        break;
      }
      if (F[i].size() >= 2 && F[i][0] == P) {
        cnt[F[i][0]] --;
        cnt[F[i][1]] ++;
        Ans[i] = F[i][1];
      }
    }
    if (cnt[P] > (M + 1) / 2) {
      cout << "NO" << '\n';
      continue;
    }
    int Q = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    if (cnt[Q] > (M + 1) / 2) {
      bool ok = false;
      for (int i = 0; i < M; ++i) {
        if (ok) {
          break;
        }
        if (Ans[i] == Q) {
          for (int j : F[i]) {
            if (j != Q && cnt[j] + 1 <= (M + 1) / 2) {
              Ans[i] = j;
              cnt[j] ++;
              cnt[Q] --;
              ok = true;
              break;
            } 
          } 
        }
      } 
    }
    if (*max_element(cnt.begin(), cnt.end()) > (M + 1) / 2) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < M; ++i) {
      cout << Ans[i] + 1 << " \n"[i == M - 1];
    }
  }
}
