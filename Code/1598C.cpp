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
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    long long ans = 0;
    map<long long, int> mp;
    for (int i = 0; i < n; ++i) {
      ans += mp[1ll * n * a[i]]; 
      mp[2ll * sum - 1ll * n * a[i]]++;
    }
    cout << ans << '\n';
  }
}
