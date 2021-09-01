#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int> (m));
  for (int i = 0; i < n * m; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    v[x][y] = i;
  }
  vector<long long> sum(n * m);
  for (int i = 0; i < n; ++i) {
    vector<int> mn(m, n * m);
    for (int j = i; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        mn[k] = min(mn[k], v[j][k]);
      }
      vector<int> st;
      vector<int> l(m);
      for (int j = 0; j < m; ++j) {
        while (!st.empty() && mn[j] < mn[st.back()]) {
          st.pop_back();
        }
        l[j] = st.empty() ? -1 : st.back();
        st.push_back(j);
      }
      vector<int> r(m);
      st.clear();
      for (int j = m - 1; j >= 0; --j) {
        while (!st.empty() && mn[j] < mn[st.back()]) {
          st.pop_back();
        }
        r[j] = st.empty() ? m : st.back();
        st.push_back(j);
      }
      for (int j = 0; j < m; ++j) {
        sum[mn[j]] += 1ll * (j - l[j]) * (r[j] - j); 
      }
    }
  }
  long long ans = 1ll * n * (n + 1) * m * (m + 1) / 4;
  for (int i = 0; i < n * m; ++i) {
    ans -= sum[i];
    cout << ans << '\n';
  }
}
