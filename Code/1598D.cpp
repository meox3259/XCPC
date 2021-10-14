#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      a[i]--;
      b[i]--;
    }
    vector<vector<long long>> choose(n + 1, vector<long long> (4));
    vector<int> ca(n);
    for (int i : a) {
      ca[i]++;
    }
    vector<int> cb(n);
    for (int i : b) {
      cb[i]++;
    }
    long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i) {
      ans -= 1ll * (ca[a[i]] - 1) * (cb[b[i]] - 1);
    }
    cout << ans << '\n';
  }
}
