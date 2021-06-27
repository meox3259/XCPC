#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long power(long long X, long long t) {
  long long ret = 1;
  for (; t; t >>= 1, X = X * X % P) {
    if (t & 1) {
      ret = ret * X % P;
    }
  }
  return ret;
}
int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> fac(K + N + 1);
  fac[0] = 1;
  for (int i = 1; i <= K + N; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  vector<long long> inv(K + N + 1);
  inv[K + N] = power(fac[K + N], P - 2);
  for (int i = K + N; i >= 1; --i) {
    inv[i - 1] = inv[i] * i % P;
  }
  auto C = [&] (int N, int M) -> long long {
    if (N < M) {
      return 0LL;
    }
    return fac[N] * inv[M] % P * inv[N - M] % P;
  };
  vector<int> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<int> Pos(N);
  for (int i = 0; i < N; ++i) {
    Pos[S[i]] = i;
  }
  int cur = 0;
  int last = -2;
  vector<int> block;
  for (int i = 0; i < N; ++i) {
    if ((S[i] == N - 1 ? -1 : Pos[S[i] + 1]) > last) {
      last = (S[i] == N - 1 ? -1 : Pos[S[i] + 1]);
      cur ++;
    } else {
      block.push_back(cur);
      cur = 1;
      last = -2;
    }
    last = (S[i] == N - 1 ? -1 : Pos[S[i] + 1]);
  }
  if (cur != 0) {
    block.push_back(cur);
  }
  int M = accumulate(block.begin(), block.end(), 0) - block.size(); 
  long long Ans = 0;
  for (int i = 0; i <= M; ++i) {
    Ans += C(K, N - i) * C(M, i) % P; 
    Ans %= P;
  }
  cout << Ans << '\n';
}
