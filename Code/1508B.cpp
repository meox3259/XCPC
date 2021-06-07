#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    long long K;
    cin >> N >> K;
    long long Mul = 1;
    bool ok = true;
    for (int i = 0; i < N - 1; ++i) {
      if (Mul >= K) {
        break;
      } 
      Mul *= 2;
    }
    if (Mul < K) {
      ok = false;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    int bit = 1;
    while ((1LL << (bit - 1)) < K) {
      bit ++;
    }
    if (K == (1LL << (bit - 1))) {
      for (int i = 0; i < N - bit; ++i) {
        cout << i + 1 << ' ';
      }
      for (int i = 0; i < bit; ++i) {
        cout << N - i << ' ';
      }
      cout << '\n';
      continue;
    }
    long long tot = K;
    vector<int> Ans;
    for (int i = 1; i <= N - bit; ++i) {
      Ans.push_back(i);
    }
    for (int i = 1; i <= bit; ) {
      for (int j = i; j <= bit; ++j) {
        if (tot <= (1LL << max((bit - j - 1), 0))) {
          for (int k = j; k >= i; --k) {
            Ans.push_back(N - bit + k);
          }
          i = j + 1;
          break;
        }  
        tot -= (1LL << (max(0, bit - j - 1)));
      } 
    }
    for (int i = 0; i < N; ++i) {
      cout << Ans[i] << " \n"[i == N - 1];
    }
  }
}
