#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
  int N; 
  cin >> N;
  vector<int> H(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> H[i];
  }
  vector<long long> dp(N + 1);
  dp[0] = 1;
  for (int i = 1; i <= N; ++i) {
    int L = i;
    int R = i;
    while (L > 0 && H[L - 1] > H[i]) {
      L --;
    }
    while (R < N && H[R + 1] > H[i]) {
      R ++;
    }
    for (int j = L; j <= R; ++j) {
      dp[j] += dp[j - 1];
      dp[j] %= P;
    } 
  }
  cout << dp[N] << '\n';
}
