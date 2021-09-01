#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> t[i];
  }
  auto solve = [&] (vector<int> a) -> double {
    vector<pair<long long, long long>> st; 
    for (int i = 0; i < n; ++i) {
      pair<long long, long long> cur = {a[i], 1}; 
      while (!st.empty() && st.back().first * cur.second > cur.first * st.back().second) {
        cur.first += st.back().first;
        cur.second += st.back().second;
        st.pop_back();
      }
      st.push_back(cur);
    }
    int l = 0;
    double ret = 0.;
    for (auto [sum, len] : st) {
      int r = l + len - 1;
      double avg = 1. * sum / (double)(len);
      for (int i = l; i <= r; ++i) {
        ret += (avg - a[i]) * (avg - a[i]); 
      }
      l += len;
    }
    return ret;
  };   
  cout << fixed << setprecision(10);
  cout << solve(s) + solve(t) << '\n';
}
