#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> Last(20, N);
  vector<vector<int>> Go(N, vector<int> (20, N));
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < 20; ++j) {
      if (A[i] >> j & 1) {
        for (int k = 0; k < 20; ++k) {
          if (Last[j] != N) {
            Go[i][k] = min(Go[i][k], Go[Last[j]][k]); 
          }
        } 
        Last[j] = i;
        Go[i][j] = i;
      }
    } 
  }
  while (Q --> 0) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    bool ok = false;
    for (int i = 0; i < 20; ++i) {
      if ((A[Y] >> i & 1) && Go[X][i] <= Y) {
        ok = true;
      }
    }
    if (ok) {
      cout << "Shi" << '\n';
    } else {
      cout << "Fou" << '\n';
    }
  }
}
