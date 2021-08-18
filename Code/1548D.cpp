#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; ++i) {
    X[i] /= 2;
    Y[i] /= 2;
  }
  vector<vector<int>> cnt(2, vector<int> (2));
  for (int i = 0; i < N; ++i) {
    cnt[X[i] & 1][Y[i] & 1] ++;
  }
  vector<vector<long long>> C(N + 1, vector<long long> (4));
  C[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= min(i, 3); ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  long long Ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      Ans += C[cnt[i][j]][3];
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      Ans += C[cnt[i][j]][2] * (N - cnt[i][j]);
    }
  }
  cout << Ans << '\n';
}
