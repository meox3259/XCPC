#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
    int N;
    cin >> N;
    vector<long long> X;
    vector<long long> Y;
    for (int i = 0; i < N + N; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == 0) {
        Y.push_back(y);
      }
      if (y == 0) {
        X.push_back(x);
      }
    }
    for (int i = 0; i < N; ++i) {
      X[i] = abs(X[i]);
    }
    for (int i = 0; i < N; ++i) {
      Y[i] = abs(Y[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long double ans = 0.;
    for (int i = 0; i < N; ++i) {
      ans += sqrt(1. * X[i] * X[i] + 1. * Y[i] * Y[i]);
    }
    cout << fixed << setprecision(15);
    cout << ans << '\n';
  }
  return 0;
}
