#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  int P = -1;
  for (int i = 0; i < N; ++i) {
    if (B[i] < B[(i + 1) % N]) {
      P = i;
    }
  }
  if (P == -1) {
    if (B[0] == 0) {
      cout << "YES" << '\n';
      for (int i = 0; i < N; ++i) {
        cout << 1 << " \n"[i == N - 1];
      }
      exit(0);
    }
    cout << "NO" << '\n';
    exit(0);
  }
  int Q = (P + 1) % N;
  long long D = 50000000000000000LL / B[Q] * B[Q];
  vector<long long> Ans(N);
  Ans[Q] = B[Q];
  long long S = accumulate(B.begin(), B.end(), 0LL);
  for (int i = 0; i < N - 1; ++i) {
    Ans[(Q + i + 1) % N] = S + D;
    S -= B[(Q + i + 1) % N];
  }
  cout << "YES" << '\n';
  for (int i = 0; i < N; ++i) {
    cout << Ans[i] << " \n"[i == N - 1];
  }
}
