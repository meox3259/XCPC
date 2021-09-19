#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> cnt(n);
  vector<ull> rnd(n);
  for (int i = 0; i < n; ++i) {
    rnd[i] = mt() * (1ull << 32) + mt();
  }
  map<ull, int> mp;
  mp[0]++;
  ull h = 0;
  vector<vector<int>> pos(n);
  vector<ull> val = {0};
  int last = 0;
  int nlast = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    h -= cnt[a[i]] * rnd[a[i]];
    cnt[a[i]] = (cnt[a[i]] + 1) % 3;
    h += cnt[a[i]] * rnd[a[i]];
    pos[a[i]].push_back(i);
    if (pos[a[i]].size() >= 4) {
      nlast = max(nlast, pos[a[i]][(int)pos[a[i]].size() - 4] + 1);
    }
    for (int j = last; j < nlast; ++j) {
      mp[val[j]]--; 
    }
    ans += mp[h];
    mp[h]++;
    last = nlast;
    val.push_back(h);
  }
  cout << ans << '\n';
}
