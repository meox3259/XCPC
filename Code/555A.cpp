#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> M(K);
  vector<vector<int>> A(K);
  for (int i = 0; i < K; ++i) {
    cin >> M[i];
    A[i].resize(M[i]);
    for (int j = 0; j < M[i]; ++j) {
      cin >> A[i][j];
      A[i][j] --;
    }
  }
  vector<int> Pre(N, -1);
  vector<int> Nxt(N, -1);
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < M[i] - 1; ++j) {
      Nxt[A[i][j]] = A[i][j + 1];
    }
    for (int j = 1; j < M[i]; ++j) {
      Pre[A[i][j]] = A[i][j - 1];
    }
  }
  int Ans = 0;
  int X = 0;
  while (Nxt[X] == X + 1) {
    X ++;
  }
  for (int i = X + 1; i < N; ++i) {
    if (Pre[i] != -1) {
      Ans ++;
    }
  }
  Ans += N - X - 1;
  cout << Ans << '\n';
}
