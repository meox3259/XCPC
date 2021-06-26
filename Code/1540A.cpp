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
    vector<long long> d(N);
    for (int i = 0; i < N; ++i) {
      cin >> d[i];
    }
    sort(d.begin(), d.end());
    long long Ans = d[N - 1];
    long long S = 0;
    for (int i = 0; i < N; ++i) {
      Ans -= 1LL * i * d[i];
      Ans += S;
      S += d[i];
    }
    cout << Ans << '\n';
  }
}
