#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  vector<int> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> S[i];
  }
  vector<int> vec;
  for (int i = 0; i < N; ++i) {
    vec.push_back(X[i]);
  }
  auto id = [&] (int V) -> int {
    return lower_bound(vec.begin(), vec.end(), V) - vec.begin() + 1;
  };
  long long Ans = (X[N - 1] + 1) % P;
  vector<long long> dp(N + 1);
  vector<long long> pre(N + 1);
  dp[1] = X[0] - Y[0];
  pre[1] = dp[1];
  if (S[0]) {
    Ans += dp[1];
    Ans %= P;
  }
  for (int i = 2; i <= N; ++i) {
    pre[i] = pre[i - 1]; 
    dp[i] = pre[i] - pre[id(Y[i - 1]) - 1] + X[i - 1] - Y[i - 1];
    dp[i] %= P;
    dp[i] += P;
    dp[i] %= P;
    pre[i] += dp[i];
    pre[i] %= P;
    Ans += dp[i] * S[i - 1];
    Ans %= P;
  }
  cout << Ans << '\n';
}
