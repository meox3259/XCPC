#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int M;
    cin >> M;
    vector<vector<int>> A(M, vector<int> (2));
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i < M; ++i) {
        cin >> A[i][j];
      }
    }
    vector<vector<long long>> pre(M + 1, vector<long long> (2));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < 2; ++j) {
        pre[i + 1][j] = pre[i][j] + A[i][j];
      }
    }
    long long Ans = numeric_limits<long long> :: max() / 2;
    for (int i = 0; i < M; ++i) {
      Ans = min(Ans, max(pre[M][0] - pre[i + 1][0], pre[i][1]));
    }
    cout << Ans << '\n';
  }
}
