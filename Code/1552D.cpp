#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    bool ok = false;
    set<int> S;
    for (int i : A) {
      if (i != 0) {
        S.insert(abs(i));
      }
    }
    if (S.size() < N) {
      ok = true;
    }
    for (int i = 0; i < N; ++i) {
      vector<int> B;
      for (int j = 0; j < N; ++j) {
        if (j != i) {
          B.push_back(A[j]);
        }
      }
      auto dfs = [&] (auto &&f, int d, int V) -> void {
        if (abs(V) == abs(A[i])) {
          ok = true;
        } 
        if (d == N - 1) {
          return;
        }
        f(f, d + 1, V + B[d]);
        f(f, d + 1, V - B[d]);
        f(f, d + 1, V);
      };
      dfs(dfs, 0, 0);
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
