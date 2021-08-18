#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> st;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && p[i] > p[st.back()]) {
      st.pop_back();
    }
    l[i] = st.empty() ? 0 : st.back() + 1;
    st.push_back(i);
  }
  st.clear();
  vector<int> r(n);
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && p[i] > p[st.back()]) {
      st.pop_back();
    }
    r[i] = st.empty() ? n - 1 : st.back() - 1;
    st.push_back(i);
  }
  vector<int> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    pos[p[i]] = i;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i - l[i] < r[i] - i) {
      for (int j = l[i]; j < i; ++j) {
        int nxt = pos[p[i] - p[j]];
        if (i < nxt && nxt <= r[i]) {
          ans ++;
        }
      }
    } else {
      for (int j = i + 1; j <= r[i]; ++j) {
        int nxt = pos[p[i] - p[j]];
        if (l[i] <= nxt && nxt < i) {
          ans ++;
        }
      }
    }
  }
  cout << ans << '\n';
}
