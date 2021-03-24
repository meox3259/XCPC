#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<int> cnt(2);
  long long Ans = 0;
  for (int i = 0; i < N; ++i) {
    int one = 0;
    for (int j = 0; j < M; ++j) {
      one += (S[i][j] == '1');
    }
    Ans += cnt[(one & 1) ^ 1];
    cnt[one & 1] ++;
  }
  cout << Ans << '\n';
}
