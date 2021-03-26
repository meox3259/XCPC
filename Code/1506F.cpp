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
    vector<int> R(N + 1);
    vector<int> C(N + 1);
    R[0] = 1;
    C[0] = 1;
    for (int i = 1; i <= N; ++i) {
      cin >> R[i];
    }
    for (int i = 1; i <= N; ++i) {
      cin >> C[i];
    }
    vector<int> id(N + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {
      return R[i] < R[j];
    });
    long long Ans = 0;
    for (int i = 0; i < N; ++i) {
      int X = id[i];
      int Y = id[i + 1];
      int DR = R[Y] - R[X];
      int DC = C[Y] - C[X];
      if (R[X] + C[X] & 1) {
        Ans += (DR - DC + 1) / 2;
      } else {
        if (DR == DC) {
          Ans += DR;
        } else {
          Ans += (DR - DC) / 2;
        }
      }
    }
    cout << Ans << '\n';
  }
}
