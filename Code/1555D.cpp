#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<vector<int>> pre(N + 1, vector<int> (6));
  string B = "abc";
  int cur = 0;
  do {
    for (int i = 0; i < N; ++i) {
      pre[i + 1][cur] = pre[i][cur] + (S[i] != B[i % 3]);
    }
    cur ++;
  } while (next_permutation(B.begin(), B.end()));
  while (M --> 0) {
    int L, R;
    cin >> L >> R;
    L --;
    R --;
    int Ans = N;
    for (int i = 0; i < 6; ++i) {
      Ans = min(Ans, pre[R + 1][i] - pre[L][i]);
    }
    cout << Ans << '\n';
  }
}
