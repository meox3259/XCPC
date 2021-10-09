#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), [&] (int i, int j) {
      return i % 2 < j % 2;
    }); 
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int g = __gcd(a[i], a[j]);
        if (g > 1) {
          ans++;
        } else if (a[i] % 2 == 0) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
