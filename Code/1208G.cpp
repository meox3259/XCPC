#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << 3 << '\n';
    exit(0);
  }
  vector<bool> mark(N + 1);
  vector<int> Phi(N + 1);
  vector<int> P;
  Phi[1] = 1;
  for (int i = 2; i <= N; ++i) {
    if (!mark[i]) {
      P.push_back(i);
      Phi[i] = i - 1;
    }
    for (int j = 0; j < P.size() && i * P[j] <= N; ++j) {
      mark[i * P[j]] = true;
      if (i % P[j] == 0) {
        Phi[i * P[j]] = Phi[i] * P[j];
        break;
      }
      Phi[i * P[j]] = Phi[i] * Phi[P[j]];
    }
  }
  sort(Phi.begin(), Phi.end());
  cout << accumulate(Phi.begin(), Phi.begin() + K + 3, 0LL) << '\n';
  return 0;
}
