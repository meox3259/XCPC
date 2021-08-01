#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    long long Ans = 0;
    for (int i = 0; i < N - 1; ++i) {
      Ans = max(Ans, 1LL * A[i] * A[i + 1]);
    }
    cout << Ans << '\n';
  }
}
