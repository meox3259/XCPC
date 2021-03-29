#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  auto calc = [&] (long long N, int K) -> long long {
    long long V = N / K;
    long long M = N % K;
    return V * V * (K - M) + (V + 1) * (V + 1) * M;
  };
  priority_queue<tuple<long long, long long, int>> Q;
  for (int i = 0; i < N; ++i) {
    Q.emplace(calc(A[i], 1) - calc(A[i], 2), A[i], 1);
  }
  for (int i = 0; i < K - N; ++i) {
    auto [diff, M, j] = Q.top();
    Q.pop();
    j ++;
    Q.emplace(calc(M, j) - calc(M, j + 1), M, j);
  }
  long long Ans = 0;
  while (!Q.empty()) {
    auto [diff, M, i] = Q.top();
    Ans += calc(M, i);
    Q.pop();
  }
  cout << Ans << '\n';
}
