#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  auto mex = [&] (int x, int y) -> int {
    vector<bool> mark(3);
    mark[x] = true;
    mark[y] = true;
    for (int i = 0; i < 3; ++i) {
      if (!mark[i]) {
        return i;
      }
    }
  };
  if (n <= 1000) {
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
      cin >> a[0][i];
    }
    for (int i = 1; i < n; ++i) {
      cin >> a[i][0];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        a[i][j] = mex(a[i - 1][j], a[i][j - 1]);
      }
    }
    vector<int> ans(3);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[a[i][j]] ++;
      }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  } else {
    vector<vector<int>> a(n);
    for (int i = 0; i < 4; ++i) {
      a[i].resize(n);
    }
    for (int i = 4; i < n; ++i) {
      a[i].resize(4);
    }
    for (int i = 0; i < n; ++i) {
      cin >> a[0][i];
    }
    for (int i = 1; i < n; ++i) {
      cin >> a[i][0];
    }
    for (int i = 1; i < 4; ++i) {
      for (int j = 1; j < n; ++j) {
        a[i][j] = mex(a[i - 1][j], a[i][j - 1]);
      }
    }
    for (int i = 4; i < n; ++i) {
      for (int j = 1; j < 4; ++j) {
        a[i][j] = mex(a[i - 1][j], a[i][j - 1]);
      } 
    }
    vector<long long> ans(3);
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[a[i][j]] ++;
      }
    }
    for (int i = 4; i < n; ++i) {
      for (int j = 0; j < 4; ++j) {
        ans[a[i][j]] ++;
      }
    }
    for (int j = 3; j < n; ++j) {
      ans[a[3][j]] += n - 1 - j;
    }
    for (int i = 4; i < n; ++i) {
      ans[a[i][3]] += n - 1 - i;
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
}
