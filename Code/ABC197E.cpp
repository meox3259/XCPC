#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> X(N);
  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> C[i];
    C[i] --;
  }
  vector<int> S;
  for (int i : C) {
    S.push_back(i); 
  }
  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());
  int M = S.size();
  vector<long long> L(M, Inf);
  vector<long long> R(M, -Inf);
  auto id = [&] (int P) -> int {
    return lower_bound(S.begin(), S.end(), P) - S.begin();
  };
  for (int i = 0; i < N; ++i) {
    int j = id(C[i]);
    L[j] = min(L[j], X[i]);
    R[j] = max(R[j], X[i]);
  }
  vector<vector<long long>> dp(M + 1, vector<long long> (2, Inf));
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 0; i < M; ++i) {
    long long P0 = (i == 0 ? 0 : L[i - 1]);
    long long P1 = (i == 0 ? 0 : R[i - 1]);
    dp[i + 1][0] = min(dp[i][0] + abs(P0 - R[i]) + abs(R[i] - L[i]), dp[i][1] + abs(P1 - R[i]) + abs(R[i] - L[i])); 
    dp[i + 1][1] = min(dp[i][0] + abs(P0 - L[i]) + abs(R[i] - L[i]), dp[i][1] + abs(P1 - L[i]) + abs(R[i] - L[i]));
  }
  cout << min(dp[M][0] + abs(L[M - 1]), dp[M][1] + abs(R[M - 1])) << '\n';
}
