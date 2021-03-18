#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    P[i] --;
  }
  vector<int> Pos(N);
  for (int i = 0; i < N; ++i) {
    Pos[P[i]] = i;
  }
  vector<pair<int, int>> ans;
  auto Swap = [&] (int i, int j) -> void {
    int X = P[i];
    int Y = P[j];
    swap(Pos[X], Pos[Y]);
    swap(P[i], P[j]);
    ans.emplace_back(i, j);
  };
  for (int i = 1; i < N - 1; ++i) {
    if (P[i] != i) {
      int X = Pos[i];
      if (abs(X - 0) * 2 >= N) {
        Swap(0, X);
        if (abs(i - 0) * 2 >= N) {
          Swap(0, i);
        } else {
          Swap(0, N - 1);
          Swap(i, N - 1);
        }
      } else {
        Swap(X, N - 1);
        if (abs(N - 1 - i) * 2 >= N) {
          Swap(N - 1, i);
        } else {
          Swap(N - 1, 0);
          Swap(0, i);
        }
      }
    } 
  }
  if (P[0] != 0) {
    Swap(0, N - 1);
  }
  cout << ans.size() << '\n';
  for (auto [X, Y] : ans) {
    cout << X + 1 << ' ' << Y + 1 << '\n';
  }
  return 0;
}
