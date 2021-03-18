#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    P[i] --;
  }
  vector<pair<int, int>> ans;
  auto Swap = [&] (int i, int j) -> bool {
    if (A[i] <= B[P[i]] || A[j] <= B[P[j]]) {
      return false;
    }
    swap(P[i], P[j]);
    ans.emplace_back(i, j);
    return true;
  };
  vector<int> id(N);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&] (int i, int j) {
    return A[i] > A[j];
  });
  for (int X = 0; X < N; ++X) {
    int i = id[X];
    while (P[i] != i) {
      if (!Swap(i, P[i])) {
        cout << -1 << '\n';
        exit(0);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto [X, Y] : ans) {
    cout << X + 1 << ' ' << Y + 1 << '\n';
  }
}
