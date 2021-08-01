#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    long long Ans = -INF;
    if (N <= 300) {
      for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
          Ans = max(Ans, 1LL * (i + 1) * (j + 1) - 1LL * K * (A[i] | A[j])); 
        }
      }
      cout << Ans << '\n';
    } else {
      for (int i = N - 1; i >= N - 300; --i) {
        for (int j = i - 1; j >= N - 300; --j) {
          Ans = max(Ans, 1LL * (i + 1) * (j + 1) - 1LL * K * (A[i] | A[j]));
        }
      }
      cout << Ans << '\n';
    }
  }
}
