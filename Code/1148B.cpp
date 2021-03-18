#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  vector<long long> t(2);
  cin >> N >> M >> t[0] >> t[1] >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<long long> B(M);
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }
  if (N <= K || M <= K) {
    cout << -1 << '\n';
    exit(0);
  }
  long long ans = -Inf;
  bool ok = true;
  for (int i = 0; i <= min(K, N - 1); ++i) {
    int j = lower_bound(B.begin(), B.end(), A[i] + t[0]) - B.begin();   
    int d = K - i;
    if (j + d < M) {
      ans = max(ans, B[j + d] + t[1]); 
    } else {
      ok = false;
    }
  }
  if (ok) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
