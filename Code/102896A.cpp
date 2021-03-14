#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  vector<tuple<int, int, int>> ans(A + B, { -1, -1, -1 });
  int N = 0;
  auto divide = [&] (auto &&f, int A, int B) -> int {
    if (A < 0 || B < 0) {
      cout << -1 << '\n';
      exit(0);
    }
    if (A == 0 && B == 0) {
      return -1;
    }
    if (B == 0 && A % 2 == 0) {
      cout << -1 << '\n';
      exit(0);
    }
    int X = N ++;
    if (A != 0) {
      if (A % 2 == 1) {
        ans[X] = { 2, f(f, A / 2, B / 2), f(f, A / 2, B - B / 2) };
      } else {
        ans[X] = { 2, f(f, A - 1 - (A - 1) / 2, (B - 1) / 2), f(f, (A - 1) / 2, B - (B - 1) / 2) }; 
      }
    } else {
      ans[X] = { 1, f(f, A, (B - 1) / 2), f(f, A, B - 1 - (B - 1) / 2) }; 
    }
    return X;
  };
  divide(divide, B, A);
  for (auto [W, X, Y] : ans) {
    cout << W << ' ' << X + 1 << ' ' << Y + 1 << '\n';
  }
  return 0;
}
