#include <bits/stdc++.h>
using namespace std;
const int MOD = 1145141919;
int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  long long seed = mt() * 100000 + 100000;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<long long> h(N + 1);
  vector<long long> Pow(N + 1);
  Pow[0] = 1;
  for (int i = 0; i < N; ++i) {
    Pow[i + 1] = Pow[i] * seed % MOD;
  }
  for (int i = 0; i < N; ++i) {
    h[i + 1] = (h[i] + Pow[i] * S[i]) % MOD;
  }
  int P = 1;
  for (int i = 2; i <= N; ++i) {
    int Len = P + i;
    int L = -1;
    int R = Len + 1;
    while (R - L > 1) {
      int Mid = L + R >> 1;
      long long hash1;
      if (Mid <= i) {
        hash1 = h[Mid];
      } else {
        hash1 = (h[i] + h[Mid - i] * Pow[i]) % MOD;
      }
      long long hash2;
      if (Mid <= P) {
        hash2 = h[Mid];
      } else {
        hash2 = (h[P] + h[Mid - P] * Pow[P]) % MOD;
      }
      if (hash1 == hash2) {
        L = Mid;
      } else {
        R = Mid;
      }
    }
    if (L < Len) {
      char c1;
      if (L < i) {
        c1 = S[L];
      } else {
        c1 = S[L - i];
      }
      char c2;
      if (L < P) {
        c2 = S[L];
      } else {
        c2 = S[L - P];
      }
      if (c1 < c2) {
        P = i;
      }
    }
  }
  string Ans = "";
  for (int i = 0; i < K; ++i) {
    Ans += S[i % P];
  }
  cout << Ans << '\n';
}

