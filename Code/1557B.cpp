#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {
      return a[i] < a[j];
    });
    vector<int> rnk(n);
    for (int i = 0; i < n; ++i) {
      rnk[id[i]] = i;
    }
    int s = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (rnk[i] + 1 != rnk[i + 1]) {
        s ++;
      }
    }
    if (s > k - 1) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
}
