#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> f(n);
  vector<int> c(n);
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    a[i] --;
    b[i] --;
    if (a[i] < n && b[i] < n) {
      ok = false;
    }
    int cost = 0;
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
      cost = 1;
    }
    if (a[i] < n) {
      f[a[i]] = b[i];
      c[a[i]] = cost;
    }
  }
  if (!ok) {
    cout << -1 << '\n';
    exit(0);
  }
  vector<int> suf(n + 1);
  suf[n] = -1;
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = max(f[i], suf[i + 1]);
  }
  vector<int> pre(n + 1);
  pre[0] = f[0];
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = min(f[i + 1], pre[i]);
  }
  vector<int> seq0;
  vector<int> seq1;
  int cost0 = 0;
  int cost1 = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (seq0.empty() || f[seq0.back()] > f[i]) {
      seq0.push_back(i);
      cost0 += c[i]; 
    } else if (seq1.empty() || f[seq1.back()] > f[i]) {
      seq1.push_back(i);
      cost1 += c[i];
    } else {
      cout << -1 << '\n';
      exit(0);
    }
    if (pre[i] > suf[i + 1]) {
      ans += min(cost0 + (int)seq1.size() - cost1, cost1 + (int)seq0.size() - cost0); 
      seq0.clear();
      seq1.clear();
      cost0 = 0;
      cost1 = 0;
    }
  }
  cout << ans << '\n';
}
