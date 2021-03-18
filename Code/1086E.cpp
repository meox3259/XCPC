#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
    }
    return sum;
  }
  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};
int Pow(int x, int t) {
  int ret = 1;
  for (; t; t >>= 1, x = 1LL * x * x % P) {
    if (t & 1) {
      ret = 1LL * ret * x % P;
    }
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
      A[i][j] --;
    }
  }
  vector<int> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % P;
  }
  vector<vector<int>> dp(N + 1, vector<int> (N + 1));
  for (int i = 0; i <= N; ++i) {
    dp[i][0] = fac[i];
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + P) % P;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    FenwickTree<int> demand(N);
    FenwickTree<int> Ndemand(N);
    int K = 0;
    for (int j = 0; j < N; ++j) {
      if (i != 0) {
        demand.add(j, 1);
        K ++;
      } else {
        Ndemand.add(j, 1); 
      }
    }
    int delta = 0;
    for (int j = 0; j < N - 1; ++j) {
      int X = demand.query(A[i][j] - 1);
      int Y = Ndemand.query(A[i][j] - 1);
      if (i > 0) {
        if (demand.range(A[i - 1][j], A[i - 1][j])) {
          X -= (A[i - 1][j] < A[i][j]); 
          demand.add(A[i - 1][j], -1);
          Ndemand.add(A[i - 1][j], 1);
          K --;
        }
      }
      if (K > 0) {
        delta += 1LL * X * dp[N - 1 - j][K - 1] % P;
        delta %= P;
      }
      delta += 1LL * Y * dp[N - 1 - j][K] % P;
      delta %= P;
      if (demand.range(A[i][j], A[i][j])) {
        demand.add(A[i][j], -1);
        K --;
      } else {
        Ndemand.add(A[i][j], -1);
      }
    }
    ans += 1LL * delta * Pow(dp[N][N], N - 1 - i) % P;
    ans %= P;
  }
  cout << ans << '\n';
  return 0;
}
