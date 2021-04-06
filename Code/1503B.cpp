#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> odd;
  vector<pair<int, int>> even;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if ((i + j) & 1) {
        odd.emplace_back(i, j);
      } else {
        even.emplace_back(i, j);
      }
    }
  }
  auto put = [&] () -> void {
    int A;
    cin >> A;
    if (A == 1) {
      if (!even.empty()) {
        auto [X, Y] = even.back();
        even.pop_back();
        cout << 2 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      } else {
        auto [X, Y] = odd.back();
        odd.pop_back();
        cout << 3 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      }
    }
    if (A == 2) { 
      if (!odd.empty()) {
        auto [X, Y] = odd.back();
        odd.pop_back();
        cout << 1 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      } else {
        auto [X, Y] = even.back();
        even.pop_back();
        cout << 3 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      }
    }
    if (A == 3) {
      if (!odd.empty()) {
        auto [X, Y] = odd.back();
        odd.pop_back();
        cout << 1 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      } else {
        auto [X, Y] = even.back();
        even.pop_back();
        cout << 2 << ' ' << X + 1 << ' ' << Y + 1 << endl;
      }
    }
  };
  for (int i = 0; i < N * N; ++i) {
    put();
  }
}
